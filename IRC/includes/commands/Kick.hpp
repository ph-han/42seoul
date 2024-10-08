#pragma once
#include "Server.hpp"
#include "Command.hpp"

class Kick : public Command
{
	private:
		bool handleException();
	public:
		Kick(uintptr_t fd, std::vector<std::string> parsedCommand);
		~Kick();
		virtual void execute();
};
