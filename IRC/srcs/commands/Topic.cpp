#include "Topic.hpp"

Topic::Topic(uintptr_t fd, std::vector<std::string> parsedCommand)
	: Command(fd, parsedCommand) {}

Topic::~Topic() {}

bool Topic::handleException()
{
	UserAccount& curUser = Database::getInstance()->getAccount(_fd);

	if (curUser.isActive() == false)
	{
		_DB->sendToClient(_fd, _fd, "", "You need to login first", SERVER);
		return true;
	}
	if (_parsedCommand.size() < 2)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NEEDMOREPARAMS), " :Not enough parameters", SERVER);
		return true;
	}
	if (findChannel(_parsedCommand[1]) == -1)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NOSUCHCHANNEL), _parsedCommand[1] + " :No such Channel", SERVER);
		return true;
	}
	Channel& curChannel = Database::getInstance()->getChannel(findChannel(_parsedCommand[1]));
	if (curChannel.isMemberExists(_fd) == false)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NOTONCHANNEL), _parsedCommand[1] + " :You're not on that channel", SERVER);
		return true;
	}
	return false;
}

bool Topic::printTopic(int chIdx)
{
	Channel &curChannel = Database::getInstance()->getChannel(chIdx);

	if (_parsedCommand.size() == 2)
	{
		if (curChannel.getTopic().length() == 0)
		{
			_DB->sendToClient(_fd, _fd, codeToString(RPL_NOTOPIC), _parsedCommand[1] + " :No topic is set", SERVER);
			return true;
		}
		else
		{
			_DB->sendToClient(_fd, _fd, codeToString(RPL_TOPIC), _parsedCommand[1] + " :" + curChannel.getTopic(), SERVER);
			return true;
		}
	}
	return false;
}

bool Topic::checkAuth(int chIdx)
{
	Channel &curChannel = Database::getInstance()->getChannel(chIdx);

	if (curChannel.checkMode("t") && curChannel.isAdmin(_fd) == false)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_CHANOPRIVSNEEDED), _parsedCommand[1] + " :You're not channel operator", SERVER);
		return true;
	}
	return false;
}

void Topic::execute()
{
	int chIdx = -1;
	std::string msg;

	if (handleException())
		return ;
	chIdx = findChannel(_parsedCommand[1]);
	if (printTopic(chIdx))
		return ;

	if (checkAuth(chIdx))
		return ;
	Channel &curChannel = Database::getInstance()->getChannel(chIdx);
	std::string topic = makeMessage(2);
	size_t	pos = topic.find(':');
	if (pos != std::string::npos)
		topic = topic.erase(pos, 1);
	curChannel.setTopic(topic);
	curChannel.announce(_fd, _parsedCommand[0], " " + _parsedCommand[1] + " :" + curChannel.getTopic(), false);
}
