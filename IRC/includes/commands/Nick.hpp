#pragma once

#include "Command.hpp"

class Nick : public Command
{
	private:
		bool handleException();
	public:
		Nick( uintptr_t fd, std::vector<std::string> parsedCommand);
		~Nick();
		virtual void execute();
};
