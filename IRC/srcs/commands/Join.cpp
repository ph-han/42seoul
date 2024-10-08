#include "Join.hpp"

Join::Join(uintptr_t fd, std::vector<std::string> parsedCommand)
	: Command(fd, parsedCommand) {}

Join::~Join() {}

bool Join::handleException()
{
	if (_DB->getAccount(_fd).isActive() == false)
	{
		_DB->sendToClient(_fd, _fd, "", _parsedCommand[0] + " :You need to pass first", SERVER);
		return true;
	}
	if (_parsedCommand.size() < 2 || _parsedCommand.size() > 3)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_NEEDMOREPARAMS), " :Not enough parameters", SERVER);
		return true;
	}
	if (_parsedCommand[1][0] != '#')
	{
		_DB->sendToClient(_fd, _fd, "", _parsedCommand[0] + " :channel name have to start with '#'", SERVER);
		return true;
	}
	return false;
}


bool Join::checkChMode(int chIdx)
{
	Channel& curChannel = _DB->getChannel(chIdx);

	if (curChannel.checkMode("k") && curChannel.getKey() != _parsedCommand[2])
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_BADCHANNELKEY), _parsedCommand[1] + " :Cannot join channel (+k)", SERVER);
		return true;
	}
	else if (curChannel.checkMode("l") && curChannel.getLimit() == curChannel.getUserCount())
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_CHANNELISFULL), _parsedCommand[1] + " :Cannot join channel (+l)", SERVER);
		return true;
	}
	else if (curChannel.checkMode("i") && curChannel.isMemberExists(_fd) == false)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_INVITEONLYCHAN), _parsedCommand[1] + " :Cannot join channel (+i)", SERVER);
		return true;
	}
	return (false);
}

void Join::execute()
{
	int chIdx = -1;
	bool oper = _DB->getAccount(_fd).isRoot() ? OPER : MEMBER;

	if (handleException())
		return ;
	if (findChannel(_parsedCommand[1]) == -1)
	{
		const std::string key = _parsedCommand.size() == 2 ? "" : _parsedCommand[2];
		if (isPrintable(_parsedCommand[1]) == false || _parsedCommand[1].length() > 50)
		{
			_DB->sendToClient(_fd, _fd, codeToString(ERR_ERRONEUSNICKNAME), _parsedCommand[1] + " :Erroneous channel name", SERVER);
			return ;
		}
		_DB->addChannel(_parsedCommand[1], key);
		oper = true;
	}
	chIdx = findChannel(_parsedCommand[1]);
	if (_DB->getChannel(chIdx).isMemberExists(_fd))
		return ;
	if (_DB->getAccount(_fd).isRoot() == false && checkChMode(chIdx))
		return ;
	_DB->getChannel(chIdx).join(_fd, oper, ONLINE);
	_DB->getChannel(chIdx).announce(_fd, _parsedCommand[0], _parsedCommand[1], false);
	_DB->sendToClient(_fd, _fd, codeToString(RPL_TOPIC), _parsedCommand[1] + " :" + _DB->getChannel(chIdx).getTopic(), SERVER);
	_DB->sendToClient(_fd, _fd, codeToString(RPL_CHANNELMODEIS), _parsedCommand[1] + " :" + _DB->getChannel(chIdx).getMode(), SERVER);
	std::string members = _DB->getChannel(chIdx).generateFormattedMemberNames();
	_DB->sendToClient(_fd, _fd, codeToString(RPL_NAMREPLY), "= " + _parsedCommand[1] + " :" + members, SERVER);
	_DB->sendToClient(_fd, _fd, codeToString(RPL_ENDOFNAMES), _parsedCommand[1] + " :End of /NAMES list", SERVER);
	_DB->sendToClient(_fd, _fd, "PRIVMSG", " " + _DB->getChannel(chIdx).getName() + " :바른말 고고운운말말", BOT);
}
