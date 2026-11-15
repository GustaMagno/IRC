#include "Server.hpp"

int	parsingArg(char **argv, int &serverPort, std::string &password)
{
	std::stringstream ss(argv[1]);

	if (!(ss >> serverPort && ss.eof()))
		return (0);
	password = argv[2];
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