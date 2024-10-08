#pragma once
#include "Server.hpp"

enum StatusCode
{
	RPL_WELCOME = 001,	// user
	RPL_YOURHOST = 002, // user
	RPL_CREATED = 003,	// user
	RPL_MYINFO = 004,	// user

	RPL_NOTOPIC = 331,		 // topic
	RPL_TOPIC = 332,	 	 // join, topic
	RPL_CHANNELMODEIS = 324, // join, mode
	RPL_INVITING = 341,		 // invite
	RPL_NAMREPLY = 353,		 // join
	RPL_ENDOFNAMES = 366,	 // join
	RPL_YOUREOPER = 381,	 // oper

	ERR_NOSUCHNICK = 401,		// invite, privmsg
	ERR_NOSUCHSERVER = 402,		// ping
	ERR_NOSUCHCHANNEL = 403,	// kick, topic, mode
	ERR_CANNOTSENDTOCHAN = 404, // privmsg
	ERR_NOORIGIN = 409,			// ping
	ERR_NORECIPIENT = 411,		// privmsg
	ERR_NOTEXTTOSEND = 412,		// privmsg
	ERR_NONICKNAMEGIVEN = 431,	// nick, kick
	ERR_ERRONEUSNICKNAME = 432, // nick, join
	ERR_NICKNAMEINUSE = 433,	// nick
	ERR_USERNOTINCHANNEL = 441, // kick, mode
	ERR_NOTONCHANNEL = 442,		// kick, topic
	ERR_USERONCHANNEL = 443,	// invite
	ERR_NEEDMOREPARAMS = 461,	// pass, user, join, invite, topic, oper, mode, part
	ERR_ALREADYREGISTRED = 462, // pass, user
	ERR_PASSWDMISMATCH = 464,	// oper
	ERR_KEYSET = 467,			// mode
	ERR_CHANNELISFULL = 471,	// join
	ERR_UNKNOWNMODE = 472,		// mode
	ERR_INVITEONLYCHAN = 473,	// join
	ERR_BADCHANNELKEY = 475,	// join
	ERR_CHANOPRIVSNEEDED = 482, // kick, invite, topic, mode
};

class Command
{
	protected :
		uintptr_t _fd;
		Database * _DB;
		std::vector<std::string> _parsedCommand;
		std::string codeToString(const int &statusCode) const;

	public :
		Command(uintptr_t fd, std::vector<std::string> parsedCommand);
		virtual ~Command();
		uintptr_t getFd() const;
		int findNick(const std::string &nick) const;
		int findChannel(const std::string &name) const;
		bool isPrintable(const std::string &str);
		virtual void execute() = 0;
		std::string makeMessage(size_t idx);
};
