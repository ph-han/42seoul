#include "Server.hpp"

int main(int ac, char *av[])
{
	std::string port;
	std::string password;

	if (ac != 3)
		return 1;
		
	port = av[1];
	password = av[2];
	try
	{
		Server server(port, password);
		server.start();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
