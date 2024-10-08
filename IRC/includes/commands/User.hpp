#pragma once

#include "Command.hpp"

class User : public Command
{
	private:
		bool 		handleException();
		std::string makeRealname();
	public:
		User(uintptr_t fd, std::vector<std::string> temp_split);
		~User();

		virtual void execute();
};