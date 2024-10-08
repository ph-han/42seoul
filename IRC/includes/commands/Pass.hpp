#pragma once

#include "Command.hpp"

class Pass : public Command
{
	private:
		std::string _password;
		bool	handleException();
	public:
		Pass(uintptr_t fd, std::vector<std::string> parsedCommand, std::string password);
		~Pass();
		virtual void execute();
};
