#include "Mode.hpp"

Mode::Mode(uintptr_t fd, std::vector<std::string> parsedCommand)
	: Command(fd, parsedCommand) {}

Mode::~Mode() {}

bool Mode::handleException()
{
	if (_DB->getAccount(_fd).isActive() != true)
	{
		_DB->sendToClient(_fd, _fd, "", _parsedCommand[0] + " :Activate first!", SERVER);
		return true;
	}
	if (_parsedCommand.size() < 3)
	{
		if (_parsedCommand.size() != 2)
		{
			_DB->sendToClient(_fd, _fd, codeToString(ERR_NEEDMOREPARAMS), " :Not enough parameters", SERVER);
			return true;
		}
		else
		{	
			int chIdx = _DB->search(_parsedCommand[1], CHANNEL);
			if (chIdx == -1)
			{
				_DB->sendToClient(_fd, _fd, codeToString(ERR_NOSUCHCHANNEL), _parsedCommand[1] + " :No such Channel", SERVER);
				return true;
			}
			Channel& curChannel = _DB->getChannel(chIdx);
			_DB->sendToClient(_fd, _fd, codeToString(RPL_CHANNELMODEIS), _parsedCommand[1] + " :" + curChannel.getMode(), SERVER);
			return true;
		}
	}
	if (_parsedCommand[1].front() != '#')
		return true;
	Channel& curChannel = _DB->getChannel(_DB->search(_parsedCommand[1], CHANNEL));
	if (curChannel.isMemberExists(_fd) == false || curChannel.isAdmin(_fd) == false)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_CHANOPRIVSNEEDED), _parsedCommand[0] + " :You are not channel operator!!", SERVER);
		return true;
	}
	return false;		
}

void Mode::execute()
{
	if (handleException())
		return ;
	if (checkMode(_parsedCommand[2]) == false)
		return ;
	if (checkParams(_parsedCommand[2]) == false)
		return ;
		Channel& curChannel = _DB->getChannel(_DB->search(_parsedCommand[1], CHANNEL));
	chmod(curChannel, _parsedCommand[2]);
}

bool Mode::checkMode(std::string& mode)
{
	const std::string modeList = "itklo+-";
	std::string myMode;
	std::string opCode = "+";

	for (size_t i = 0; i < mode.length(); i++)
	{
		if (modeList.find(mode[i]) == std::string::npos)
		{
			std::string errMsg = mode + " :is unknown mode char to me for " + _parsedCommand[1];
			_DB->sendToClient(_fd, _fd, codeToString(ERR_UNKNOWNMODE), errMsg, SERVER);
			return false;
		}
	}
	for (size_t i = 0; i < mode.length(); i++)
	{
		if (mode[i] == '+' || mode[i] == '-')
			opCode = mode[i];
		else
			myMode += opCode + mode[i];
	}
	mode = myMode;
	return true;
}

bool Mode::checkParams(const std::string& mode)
{
	int opCode;
	int requiredParamsCount = 0;
	int commandParamsSize = _parsedCommand.size() - 3;

	for (size_t i = 0; i < mode.length(); i++)
	{
		if (mode[i] == '+' || mode[i] == '-')
			opCode = mode[i];
		else
		{
			if ((opCode == '+' && (mode[i] == 'k' || mode[i] == 'l' || mode[i] == 'o')) || \
				(opCode == '-' && (mode[i] == 'k' || mode[i] == 'o')))
				requiredParamsCount++;
		}
	}
	if (commandParamsSize != requiredParamsCount)
		return false;
	return true;
}

void Mode::chmod(Channel& channel, const std::string& mode)
{
	int opCode = '+';
	static bool (Mode::*chmodFunc[5])(Channel& channel, const int opCode, const std::string& param) = {&Mode::changeModeI, &Mode::changeModeT, &Mode::changeModeK, &Mode::changeModeL, &Mode::changeModeO};
	const std::string modeList = "itklo";
	int paramIdx = 0;
	bool successChangeMode;
	for (size_t i = 0; i < mode.length(); i++)
	{
		if (mode[i] == '+' || mode[i] == '-')
			opCode = mode[i];
		else
		{
			if ((opCode == '+' && (mode[i] == 'k' || mode[i] == 'l' || mode[i] == 'o')) || \
				(opCode == '-' && (mode[i] == 'k' || mode[i] == 'o')))
				successChangeMode = (this->*chmodFunc[modeList.find(mode[i])])(channel, opCode, _parsedCommand[3 + paramIdx++]);
			else
				successChangeMode = (this->*chmodFunc[modeList.find(mode[i])])(channel, opCode, "");
		}
	}
	if (successChangeMode)
		channel.announce(_fd, _parsedCommand[0], " " + _parsedCommand[1] + " :" + makeMessage(2), false);
}
bool Mode::changeModeI(Channel& channel, const int opCode, const std::string& param)
{
	size_t pos = channel.getMode().find('i');
	(void) param;
	if (opCode == '+')
	{
		if (pos != std::string::npos)
			return true;
		std::string currMode = channel.getMode();
		currMode += "i";
		channel.setMode(currMode);
	}
	else
	{
		if (pos == std::string::npos)
			return true;
		std::string currMode = channel.getMode();
		currMode.erase(pos, 1);
		channel.setMode(currMode);
	}
	return true;
}

bool Mode::changeModeT(Channel& channel, const int opCode, const std::string& param)
{
	size_t pos = channel.getMode().find('t');

	(void) param;
	if (opCode == '+')
	{
		if (pos != std::string::npos)
			return true;
		std::string currMode = channel.getMode();
		currMode += "t";
		channel.setMode(currMode);
	}
	else
	{
		if (pos == std::string::npos)
			return true;
		std::string currMode = channel.getMode();
		currMode.erase(pos, 1);
		channel.setMode(currMode);
	}
	return true;
}

bool Mode::changeModeK(Channel& channel, const int opCode, const std::string& param)
{
	size_t pos = channel.getMode().find('k');

	if (opCode == '+')
	{
		if (pos != std::string::npos)
		{
			_DB->sendToClient(_fd, _fd, codeToString(ERR_KEYSET), _parsedCommand[1] + " :Channel key already set", SERVER);
			return false;
		}
		std::string currMode = channel.getMode();
		currMode += "k";
		channel.setMode(currMode);
		channel.setKey(param);
	}
	else
	{
		if (pos == std::string::npos || channel.getKey() != param)
			return false;
		std::string currMode = channel.getMode();
		currMode.erase(pos, 1);
		channel.setMode(currMode);
		channel.setKey("");
	}
	return true;
}

bool Mode::changeModeL(Channel& channel, const int opCode, const std::string& param)
{
	size_t pos = channel.getMode().find('l');

	if (opCode == '+')
	{
		for (size_t i = 0; i < param.length(); i++)
			if (std::isdigit(param[i]) == 0)
				return false;
		int limit = std::atoi(param.c_str());
		if (channel.getUserCount() > limit || limit < 1)
			return false;
		channel.setLimit(limit);
		std::string currMode = channel.getMode();
		currMode += "l";
		channel.setMode(currMode);
	}
	else
	{
		if (pos == std::string::npos)
			return true;
		std::string currMode = channel.getMode();
		currMode.erase(pos, 1);
		channel.setMode(currMode);
	}
	return true;
}

bool Mode::changeModeO(Channel& channel, const int opCode, const std::string& param)
{
	bool modeO = opCode == '+' ? true : false;
	int res = channel.chopMember(param, modeO);

	if (res < 0)
	{
		_DB->sendToClient(_fd, _fd, codeToString(ERR_USERNOTINCHANNEL), param + " " + _parsedCommand[1] + " :They aren't on that channel", SERVER);
		return false;
	}
	if (res == 0)
		return false;
	return true;
}
