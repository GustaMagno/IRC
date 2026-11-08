#include "Server.hpp"

int	parsingArg(char **argv, int &serverPort, std::string &password)
{
	(void) argv;
	(void) serverPort;
	(void) password;
	return (1);
}

int main(int argc, char **argv)
{
	std::string password;
	int			serverPort;

	if (argc != 3 || !parsingArg(argv, serverPort, password))
	{
		std::cout << "Invalid arguments. Try: ./ircserver <port> <password>" << std::endl;
		return 0;
	}
	Server ircServ(serverPort, password);
}