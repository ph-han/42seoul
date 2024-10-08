#include "Nick.hpp"

Nick::Nick(uintptr_t fd, std::vector<std::string> parsedCommand)
	: Command(fd, parsedCommand) {}

Nick::~Nick() {}

bool Nick::handleException()
{
	if (_DB->getAccount(_fd).isPass() == false)
	{
		_DB->sendToClient(_fd, _fd, "", _parsedCommand[0] + " :You need to pass first", SERVER);
		return true;
	}
	if (_parsedCommand.size() != 2)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NONICKNAMEGIVEN), " :No nickname given", SERVER);
		return true;
	}
	if (isPrintable(_parsedCommand[1]) == false || _parsedCommand[1].length() > 9)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_ERRONEUSNICKNAME), _parsedCommand[1] + " :Erroneous nickname", SERVER);
		return true;
	}
	if (findNick(_parsedCommand[1]) != -1)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NICKNAMEINUSE), _parsedCommand[1] + " :Nickname is already in use", SERVER);
		return true;
	}
	return false;
}

void Nick::execute()
{
	if (handleException())
		return ;
	_DB->sendToClient(_fd, _fd, _parsedCommand[0], " :" + _parsedCommand[1], CLIENT);
	_DB->getAccount(_fd).setNickName(_parsedCommand[1]);
}
