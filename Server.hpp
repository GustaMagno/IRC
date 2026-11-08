#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <csignal>
# include <fcntl.h>
# include <unistd.h>

# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <poll.h>

class Server
{
private:
	std::vector <struct pollfd> socketList;
	std::string port;
	std::string password;
public:
	Server(int port, std::string password);
	~Server();
};

#endif