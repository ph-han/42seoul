#pragma once

#include "Command.hpp"

class Privmsg : public Command
{
	private:
		bool handleException();

	public:
		Privmsg(uintptr_t fd, std::vector<std::string> parsedCommand);
		~Privmsg();
		virtual void execute();
};