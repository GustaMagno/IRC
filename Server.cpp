#include "Server.hpp"

Server::Server(int port, std::string password)
{
	this->port = port;
	this->password = password;
}

void	Server::ServerInitSocket()
{
	serverFd = socket(AF_INET, SOCK_STREAM, 0);
	if (serverFd < 0)
		throw ServerException("Invalid Server fd");
	int opt = 1;
	if (setsockopt(serverFd, SOL_SOCKET, SO_REUSEADDR ,&opt, sizeof(opt)))
		throw ServerException("Config SO_REUSEADOR error");
	if (fcntl(serverFd, F_SETFL, O_NONBLOCK) < 0)
		throw ServerException("Error setting O_NONBLOCK socket");
	struct sockaddr_in socketStucture;
	std::memset(&socketStucture, 0, sizeof(socketStucture));
	socketStucture.sin_family = AF_INET;
	socketStucture.sin_port = htons(this->port);
	socketStucture.sin_addr.s_addr = INADDR_ANY;
	if (bind(serverFd, (struct sockaddr *)&socketStucture, sizeof(socketStucture)) < 0)
		throw ServerException("Error setting port socket");
	if (listen(serverFd, SOMAXCONN) < 0)
		throw ServerException("Error making socket listen.");
	struct pollfd pollServ;
	pollServ.fd = this->serverFd;
	pollServ.events = POLLIN;
	pollServ.revents = 0;
	this->socketList.push_back(pollServ);
}

Server::~Server()
{
}

