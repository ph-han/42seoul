#pragma once

#include "Command.hpp"

class Topic : public Command
{
	private:
		bool handleException();
		bool printTopic(int chIdx);
		bool checkAuth(int chIdx);
	public:
		Topic(uintptr_t fd, std::vector<std::string> parsedCommand);
		~Topic();
		virtual void execute();
};