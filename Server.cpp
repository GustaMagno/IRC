#include "Server.hpp"

Server::Server(int port, std::string password)
{
	this->port = port;
	this->password = password;
}

void	Server::ServerInitSocketServ()
{
	serverFd = socket(AF_INET, SOCK_STREAM, 0);
	if (serverFd < 0)
		throw ServerException("Invalid Server fd");
}

Server::~Server()
{
}

