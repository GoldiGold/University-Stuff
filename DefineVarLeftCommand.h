//
// Created by yoavst22 on 07/01/2020.
//

#ifndef ADVANCED1_HW3__DEFINEVARLEFTCOMMAND_H_
#define ADVANCED1_HW3__DEFINEVARLEFTCOMMAND_H_
#include "Command.h"
#include "SingletonObj.h"
//for code like: var x <- sim("path")
class DefineVarLeftCommand: public Command {
	std::string name;
	std::string sim;//simulator adress

 public:
	DefineVarLeftCommand(std::string varName, std::string simulator);
	void execute();
	virtual ~DefineVarLeftCommand() {}
};
#endif //ADVANCED1_HW3__DEFINEVARLEFTCOMMAND_H_
