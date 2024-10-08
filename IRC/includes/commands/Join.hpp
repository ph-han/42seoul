#pragma once
#include "Server.hpp"
#include "Command.hpp"

class Join : public Command
{
	private:
		bool handleException();
		bool checkChMode(int chIdx);
	public:
		Join(uintptr_t fd, std::vector<std::string> parsedCommand);
		~Join();
		virtual void execute();
};
