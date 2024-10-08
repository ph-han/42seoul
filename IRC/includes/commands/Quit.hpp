#pragma once

#include "Command.hpp"

class Quit : public Command
{
	private:
		bool handleException();

	public:
		Quit(uintptr_t fd, std::vector<std::string> parsedCommand);
		~Quit();
		virtual void execute();
};