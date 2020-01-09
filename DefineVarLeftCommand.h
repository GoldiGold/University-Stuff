//
// Created by yoavst22 on 07/01/2020.
//

#ifndef ADVANCED1_HW3__DEFINEVARLEFTCOMMAND_H_
#define ADVANCED1_HW3__DEFINEVARLEFTCOMMAND_H_
#include "Command.h"
#include "SingletonObj.h"

class DefineVarLeftCommand: public Command {
	std::string name;
	std::string sim;

 public:
	DefineVarLeftCommand(std::string varName, std::string simulator);
	int execute(std::string var);
	virtual ~DefineVarLeftCommand() {}
};
#endif //ADVANCED1_HW3__DEFINEVARLEFTCOMMAND_H_
