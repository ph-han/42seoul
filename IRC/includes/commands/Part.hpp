#pragma once
#include "Server.hpp"
#include "Command.hpp"

class Part : public Command
{
	private:
		bool handleException();
	public:
		Part(uintptr_t fd, std::vector<std::string> parsedCommand);
		~Part();
		virtual void execute();
};
