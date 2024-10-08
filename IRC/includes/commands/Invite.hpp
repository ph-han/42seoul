#pragma once
#include "Server.hpp"
#include "Command.hpp"

class Invite : public Command
{
	private:
		bool handleException();

	public:
		Invite(uintptr_t fd, std::vector<std::string> parsedCommand);
		~Invite();
		virtual void execute();
};
