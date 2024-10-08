#pragma once

#include "UserAccount.hpp"
#include <sys/socket.h>
#include <vector>
#include <utility>

#define ONLINE true
#define OFFLINE false
#define OPER true
#define MEMBER false

typedef unsigned long uintptr_t;

class Channel
{
private:
	int _limit;
	int _userCount;
	std::string _name;
	std::string _key;
	std::string _topic;
	std::string _mode;
	std::map<uintptr_t, std::pair<bool, bool> > _members;

public:
	Channel(std::string name, std::string key);
	~Channel();

	const std::string &getName() const;
	const std::string &getKey() const;
	const std::string &getTopic() const;
	const std::string &getMode() const;

	int getLimit() const;
	int getUserCount() const;
	int part(int fd);
	int chopMember(const std::string &nick, bool op);
	bool isMemberExists(uintptr_t fd);
	bool isInvitedMember(uintptr_t fd);
	bool isAdmin(uintptr_t fd);
	bool checkMode(const std::string &mode);
	void join(uintptr_t fd, bool oper, bool status);
	void setMode(const std::string mode);
	void setTopic(const std::string topic);
	void setLimit(const int limit);
	void setKey(const std::string key);
	void announce(uintptr_t senderFd, std::string cmd, std::string params, bool flag);
	const std::string generateFormattedMemberNames();
};
