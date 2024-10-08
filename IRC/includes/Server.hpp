#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/event.h>
#include <string>
#include <exception>
#include <vector>
#include <sstream>

#include "UserAccount.hpp"
#include "Channel.hpp"
#include "Database.hpp"

typedef unsigned long uintptr_t;

class Command;
class Server{
    private:
        std::string			_serverName;
        const std::string	_password;
		const std::string	_rootId;
		const std::string	_rootPw;
        int					_port;
        uintptr_t			_socketFd;
		Database*			_DB;

        void                        create(void);
        bool                        isValidPort(std::string port);
        void                        changeEvents(std::vector<struct kevent>& change_list, uintptr_t ident, int16_t filter);
		void		                connectClient(std::vector<struct kevent>& changeList);
        void		                disconnectClient(int clientFd);
		Command*                    createCommand(uintptr_t fd, std::vector<std::string>& buff);
        std::vector<Command*>       parsingCommand(struct kevent& currEvent);
		std::vector<std::string>    splitBuff(std::string& sendBuffer);
		std::vector<std::string>    splitSpace(std::string& st);

    public:
        Server(std::string port, std::string password);
        ~Server();

        void	start(void);
};