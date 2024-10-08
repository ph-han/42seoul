#include "Database.hpp"

Database* Database::_instance = NULL;

Database::Database() {}

Database::~Database() {}

Database* Database::getInstance()
{
	if (_instance == NULL)
		_instance = new Database();
	return _instance;
}

void Database::addAccount(uintptr_t fd)
{
	_accounts[fd].sendBuffer.clear();
}

void Database::addChannel(const std::string& name, const std::string& key)
{
	_channels.push_back(Channel(name, key));
}

UserAccount& Database::getAccount(uintptr_t fd)
{
	return _accounts[fd];
}

void Database::deleteAccount(uintptr_t fd)
{
	_accounts.erase(fd);
}

bool Database::isUserExists(uintptr_t fd)
{
	return _accounts.find(fd) != _accounts.end();
}

int	 Database::search(const std::string& target, int type)
{
	if (type == NICK)
	{
		std::map<uintptr_t ,UserAccount>::iterator it;
		for (it = _accounts.begin(); it != _accounts.end(); ++it)
			if (it->second.getNickName() == target)
				return it->first;
	}
	else if (type == CHANNEL)
	{
		for (size_t i = 0; i < _channels.size(); i++)
			if (_channels[i].getName() == target)
				return i;
	}
	return -1;
}

void Database::sendToClient(uintptr_t senderFd, uintptr_t targetFd, std::string cmd, std::string params, int flag)
{
	std::string prefix;
	std::string success;
	UserAccount sender;
	
	switch (flag)
	{
	case BOT:
		success = ":MANNER_BOT " + cmd + params + "\r\n";
		break;
	case CLIENT:
		sender = getAccount(senderFd);
		prefix = sender.getNickName() + "!" + sender.getUserName() + "@" + sender.getServerName();
		success = ":" + prefix + " " + cmd + params + "\r\n";
		break;
	case SERVER:
		sender = getAccount(senderFd);
		prefix = sender.getServerName();
		success = ":" + prefix + " " + cmd + " " + sender.getNickName() + " " + params + "\r\n";
		break;
	default:
		break;
	}
    const char *msg = success.c_str();
	int result = send(targetFd, msg, std::strlen(msg), 0);
    if (result == -1)
        throw new std::runtime_error("Error: send failed");
}

Channel& Database::getChannel(int idx)
{
	return _channels[idx];
}

void Database::deleteChannel(std::string name)
{
	int idx = search(name, CHANNEL);
	if (idx == -1)
		return ;
	_channels.erase(_channels.begin() + idx);
}