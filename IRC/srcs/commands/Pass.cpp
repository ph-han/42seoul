#include "Pass.hpp"

Pass::Pass(uintptr_t fd, std::vector<std::string> parsedCommand, std::string password)
	: Command(fd, parsedCommand), _password(password) {}

Pass::~Pass() {}

void Pass::execute()
{
	if (handleException())
		return ;
	if (_parsedCommand[1] != _password)
		_DB->getAccount(_fd).denyAccess();
	else
		_DB->getAccount(_fd).allowAccess();
}

bool Pass::handleException()
{
	if (_DB->getAccount(_fd).isActive() == true)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_ALREADYREGISTRED), " :Unauthorized command (already registered)", SERVER);
		return true;
	}
	if (_parsedCommand.size() != 2)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NEEDMOREPARAMS), " :Not enough parameters", SERVER);
		return true;
	}
	return false;
}
