#include "Kick.hpp"

Kick::Kick(uintptr_t fd, std::vector<std::string> parsedCommand)
	: Command(fd, parsedCommand) {}

Kick::~Kick() {}

bool Kick::handleException()
{
	UserAccount& curUser = Database::getInstance()->getAccount(_fd);

	if (curUser.isActive() == false)
	{
		_DB->sendToClient(_fd, _fd, "", _parsedCommand[0] + " :You need to pass first", SERVER);
		return true;
	}
	if (_parsedCommand.size() < 3)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NONICKNAMEGIVEN), " :No nickname given", SERVER);
		return true;
	}
	int channelIdx = findChannel(_parsedCommand[1]);
	if (channelIdx == -1)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NOSUCHCHANNEL), _parsedCommand[1] + " :No such Channel", SERVER);
		return true;
	}
	Channel&	 curChannel = Database::getInstance()->getChannel(channelIdx);
	if (curChannel.isMemberExists(_fd) == false)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NOTONCHANNEL), _parsedCommand[1] + " :You're not on that channel", SERVER);
		return true;
	}
	if (curChannel.isAdmin(_fd) == false)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_CHANOPRIVSNEEDED), _parsedCommand[1] + " :You're not a channel operator", SERVER);
		return true;
	}
	int targetFd = findNick(_parsedCommand[2]);
	if (targetFd == -1 || curChannel.isMemberExists(targetFd) == false)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_USERNOTINCHANNEL), _parsedCommand[2] + " " + _parsedCommand[1] + " :They aren't on that channel", SERVER);
		return true;
	}
	return false;
}

void Kick::execute()
{
	int chIdx = -1;
	int targetFd;
	std::string msg;

	if (handleException())
		return ;
	targetFd = findNick(_parsedCommand[2]);
	chIdx = findChannel(_parsedCommand[1]);
	Channel &curChannel = Database::getInstance()->getChannel(chIdx);
	curChannel.announce(_fd, _parsedCommand[0], " " + _parsedCommand[1] + " " + _parsedCommand[2] + " " + (_parsedCommand.size() >= 4 ? makeMessage(3) : _parsedCommand[2]), false);
	if (curChannel.part(targetFd) == 0)
		Database::getInstance()->deleteChannel(curChannel.getName());
}
