#include "Quit.hpp"

Quit::Quit(uintptr_t fd, std::vector<std::string> parsedCommand)
	: Command(fd, parsedCommand) {}

Quit::~Quit() {}

void Quit::execute()
{
	if (handleException())
		return ;
	UserAccount& curUser = Database::getInstance()->getAccount(_fd);
	std::vector<std::string> currentChannelList = curUser.getChannels();
	for (size_t i = 0; i < currentChannelList.size(); i++)
	{
		Channel& channel = Database::getInstance()->getChannel(findChannel(currentChannelList[i]));
		channel.announce(_fd, "PART", " " + channel.getName(), false);
		if (channel.part(_fd) == 0)
			Database::getInstance()->deleteChannel(currentChannelList[i]);
	}
	close(_fd);
	Database::getInstance()->deleteAccount(_fd);
}

bool Quit::handleException()
{
	UserAccount& curUser = Database::getInstance()->getAccount(_fd);
	if (curUser.isPass() == false)
	{
		close(_fd);
		return true;
	}
	return false;
}