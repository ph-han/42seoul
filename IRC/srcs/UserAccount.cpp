#include "UserAccount.hpp"
#include "Database.hpp"

UserAccount::UserAccount() : _pass(false), _active(false), _root(false), _realName("name"), _userName("user"), _serverName("localhost")
{
	static int	_nickIdx = 0;
	std::stringstream ss;
    ss << "default" << _nickIdx;
	_nickIdx++;
    std::string nick = ss.str();
    _nickName = nick;
}

UserAccount::~UserAccount() {}

const std::string &UserAccount::getNickName(void) const
{
    return _nickName;
}

const std::string &UserAccount::getRealName(void) const
{
    return _realName;
}

const std::string &UserAccount::getUserName(void) const
{
    return _userName;
}

const std::string &UserAccount::getHostName(void) const
{
	return _hostName;
}

const std::string &UserAccount::getServerName(void) const
{
	return _serverName;
}

const std::vector<std::string>& UserAccount::getChannels(void) const
{
	return _channels;
}

bool UserAccount::isActive(void) const
{
    return _active;
}

bool UserAccount::isPass(void) const
{
    return _pass;
}

bool UserAccount::isRoot(void) const
{
	return _root;
}

void UserAccount::setNickName(const std::string &nickName)
{
    _nickName = nickName;
}

void UserAccount::setRealName(const std::string &realName)
{
    _realName = realName;
}

void UserAccount::setUserName(const std::string &userName)
{
    _userName = userName;
}

void UserAccount::setHostName(const std::string &hostName)
{
	_hostName = hostName;
}

void UserAccount::setServerName(const std::string &serverName)
{
	_serverName = serverName;
}

void UserAccount::addChannel(int idx)
{
	Database *DB = Database::getInstance();
	_channels.push_back(DB->getChannel(idx).getName());
}

void UserAccount::deleteChannel(int idx)
{
	if (idx == -1)
		return ;
	Database *DB = Database::getInstance();
	_channels.erase(std::find(_channels.begin(), _channels.end(), DB->getChannel(idx).getName()));
}

void UserAccount::activate(void)
{
	_active = true;
}

void UserAccount::deactivate(void)
{
	_active = false;
}

void UserAccount::allowAccess(void)
{
	_pass = true;
} 

void UserAccount::denyAccess(void)
{
	_pass = false;
}

void UserAccount::authorize()
{
	_root = true;
}

void UserAccount::deauthorize()
{
	_root = false;
}
