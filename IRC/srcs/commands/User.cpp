#include "User.hpp"

User::User(uintptr_t fd, std::vector<std::string> parsedCommand)
	: Command(fd, parsedCommand) {}

User::~User() {}

bool User::handleException()
{
	if (_DB->getAccount(_fd).isPass() == false)
	{
		_DB->sendToClient(_fd, _fd, "", _parsedCommand[0] + " :You need to pass first", SERVER);
		return true;
	}
	if (_DB->getAccount(_fd).isActive() == 1)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_ALREADYREGISTRED), _parsedCommand[0] + " :Unauthorized command (already registered)", SERVER);
		return true;
	}
	if (_parsedCommand.size() < 5)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NEEDMOREPARAMS), " :Not enough parameters", SERVER);
		return true;
	}
	if (_parsedCommand[4][0] != ':')
	{
		_DB->sendToClient(_fd, _fd, "", _parsedCommand[0] + " :Wrong realname arg!", SERVER);
		return true;
	}
	return false;
}

void User::execute()
{
	if (handleException())
		return ;
	_DB->getAccount(_fd).setUserName(_parsedCommand[1]);
	_DB->getAccount(_fd).setHostName(_parsedCommand[2]);
	_DB->getAccount(_fd).setServerName(_parsedCommand[3]);
	_DB->getAccount(_fd).setRealName(makeRealname());
	_DB->getAccount(_fd).activate();
	std::string postfix = _DB->getAccount(_fd).getNickName() + "!" + _DB->getAccount(_fd).getUserName() + "@" + _DB->getAccount(_fd).getServerName();
	_DB->sendToClient(_fd, _fd, codeToString(RPL_WELCOME), "Welcome to the Internet Relay Network " + postfix, SERVER);
	_DB->sendToClient(_fd, _fd, codeToString(RPL_YOURHOST), "Your host is " + _DB->getAccount(_fd).getServerName() + ", running version 0.0.1", SERVER);
	_DB->sendToClient(_fd, _fd, codeToString(RPL_CREATED), "This server was created 24/02/02", SERVER);
	_DB->sendToClient(_fd, _fd, codeToString(RPL_MYINFO), _DB->getAccount(_fd).getServerName() + " 0.0.1 ", SERVER);
}

std::string User::makeRealname()
{
	std::string realname;

	for (int i = 4; i < (int)_parsedCommand.size(); i++)
		realname += _parsedCommand[i] + " ";
	realname.erase(std::find(realname.begin(), realname.end(), ':'));
	realname.erase(realname.find_last_not_of(" ") + 1);
	return realname;
}