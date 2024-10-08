#include "Oper.hpp"

Oper::Oper(uintptr_t fd, std::vector<std::string> parsedCommand, std::string id, std::string password)
	: Command(fd, parsedCommand), _rootId(id), _rootPw(password) {}

Oper::~Oper() {}

void Oper::execute()
{
	if (handleException())
		return ;
	UserAccount& curUser = Database::getInstance()->getAccount(_fd);

	curUser.authorize();
	_DB->sendToClient(_fd, _fd, codeToString(RPL_YOUREOPER), " :You are now an IRC operator", SERVER);
}

bool Oper::handleException()
{
	UserAccount& curUser = Database::getInstance()->getAccount(_fd);

	if (curUser.isActive() == false)
	{
		_DB->sendToClient(_fd, _fd, "", _parsedCommand[0] + " :You need to pass first", SERVER);
		return true;
	}
	if (_parsedCommand.size() != 3)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NEEDMOREPARAMS), " :Not enough parameters", SERVER);
		return true;
	}
	if (_parsedCommand[1] != _rootId || _parsedCommand[2] != _rootPw)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_PASSWDMISMATCH), " :Password incorrect", SERVER);
		return true;
	}
	if (curUser.isRoot())
	{
		_DB->sendToClient(_fd, _fd, "", " You are already root!", SERVER);
		return true;
	}
	return false;
}
