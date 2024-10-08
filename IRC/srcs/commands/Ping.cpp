#include "Ping.hpp"

Ping::Ping(uintptr_t fd, std::vector<std::string> parsedCommand)
	: Command(fd, parsedCommand) {}

Ping::~Ping() {}

void Ping::execute()
{
	if (handleException())
		return ;
	pong();
}

bool Ping::handleException()
{
	struct hostent *host_info;

	if (_parsedCommand.size() != 2)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NOORIGIN), _parsedCommand[0] + " :No origin specified", SERVER);
		return true;
	}
	host_info = gethostbyname(_parsedCommand[1].c_str());
	if (std::strcmp(_DB->getAccount(_fd).getServerName().c_str(), host_info->h_name))
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NOSUCHSERVER), _parsedCommand[0] + " :" + _parsedCommand[1] + " :No such serverd", SERVER);
		return true;
	}
	return false;
}

void Ping::pong()
{
	std::string result = "PONG " + _DB->getAccount(_fd).getServerName() + "\r\n";
	int n = send(_fd, result.c_str(), result.length(), 0);

    if (n == -1)
        throw new std::runtime_error("Error: send failed");
}
