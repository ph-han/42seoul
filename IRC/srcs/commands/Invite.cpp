#include "Invite.hpp"

Invite::Invite(uintptr_t fd, std::vector<std::string> parsedCommand)
	: Command(fd, parsedCommand) {}

Invite::~Invite() {}

void Invite::execute()
{
	int chIdx = -1;
	int targetFd;
	std::string msg;

	if (handleException())
		return ;
	targetFd = findNick(_parsedCommand[1]);
	chIdx = findChannel(_parsedCommand[2]);
	_DB->getChannel(chIdx).join(targetFd, MEMBER, OFFLINE);
	_DB->sendToClient(_fd, _fd, codeToString(RPL_INVITING), _parsedCommand[1] + " " + _parsedCommand[2], SERVER);
	_DB->sendToClient(_fd, targetFd, _parsedCommand[0], " " + _parsedCommand[1] + " :" + _parsedCommand[2], CLIENT);
}

bool Invite::handleException()
{
	int targetFd;
	UserAccount& curUser = _DB->getAccount(_fd);

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
	if ((findChannel(_parsedCommand[2]) == -1) || (targetFd = findNick(_parsedCommand[1])) == -1 || Database::getInstance()->getAccount(targetFd).isActive() == false)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NOSUCHNICK), _parsedCommand[1] + " :No such nick/channel", SERVER);
		return true;
	}
	Channel& curChannel = _DB->getChannel(findChannel(_parsedCommand[2]));
	if (curChannel.isMemberExists(_fd) == false || curChannel.isAdmin(_fd) == false)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_CHANOPRIVSNEEDED), _parsedCommand[2] + " :You're not channel operator", SERVER);
		return true;
	}
	if (curChannel.isMemberExists(targetFd) == true)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_USERONCHANNEL), _parsedCommand[1] + " " + _parsedCommand[2] + " :is already on channel", SERVER);
		return true;
	}
	return false;
}