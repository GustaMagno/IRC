#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <list>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <csignal>
# include <fcntl.h>
# include <unistd.h>
# include <exception>

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <poll.h>

class Server
{
private:
	std::vector <struct pollfd> socketList;
	std::list<int>				clientList;
	std::string 				password;
	int							port;
	int			 				serverFd;
public:
	Server(int port, std::string password);
	class ServerException : public std::exception {
	private:
		std::string _msg;
	public:
		ServerException(const std::string &msg) : _msg(msg) {}
		virtual ~ServerException() throw() {}
		virtual const char *what() const throw() {
			return _msg.c_str();
		}
	};

	void	ServerInitSocketServ();
	~Server();

	// addClient();
	// removeClient();
};

#endif