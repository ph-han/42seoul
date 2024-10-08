#pragma once
#include "Server.hpp"
#include "Command.hpp"
#include <netdb.h>

class Ping : public Command
{
	private:
		void pong();
		bool handleException();
	public:
		Ping(uintptr_t fd, std::vector<std::string> parsedCommand);
		~Ping();
		virtual void execute();
};
