#pragma once

#include "Command.hpp"

class Mode : public Command
{
	private:
		bool handleException();
		bool checkMode(std::string& mode);
		bool checkParams(const std::string& mode);

		void chmod(Channel& channel, const std::string& mode);
		bool changeModeI(Channel& channel, const int opCode, const std::string& param);
		bool changeModeT(Channel& channel, const int opCode, const std::string& param);
		bool changeModeK(Channel& channel, const int opCode, const std::string& param);
		bool changeModeL(Channel& channel, const int opCode, const std::string& param);
		bool changeModeO(Channel& channel, const int opCode, const std::string& param);
	
	public:
		Mode(uintptr_t fd, std::vector<std::string> parsedCommand);
		~Mode();
		virtual void execute();
};
