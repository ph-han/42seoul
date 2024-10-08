#pragma once
#include <iostream>
#include "UserAccount.hpp"
#include "Channel.hpp"

#define NICK	0
#define CHANNEL	1

#define CLIENT 0
#define SERVER 1
#define BOT 2

typedef unsigned long uintptr_t;

class Database
{
private:
	Database();
	static Database*					_instance;
	std::vector<Channel>				_channels;
	std::map<uintptr_t, UserAccount>	_accounts;
	
public:
	~Database();
	static Database*	getInstance();
	void				addAccount(uintptr_t fd);
	void				deleteAccount(uintptr_t fd);
	bool				isUserExists(uintptr_t fd);
	UserAccount&		getAccount(uintptr_t fd);
	void				addChannel(const std::string& name, const std::string& key);
	Channel&			getChannel(int idx);
	void				deleteChannel(std::string name);
	int					search(const std::string& target, int type);
	void				sendToClient(uintptr_t senderFd, uintptr_t targetFd, std::string cmd, std::string params, int flag);
};
