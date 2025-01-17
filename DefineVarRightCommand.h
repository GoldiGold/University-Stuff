//
// Created by yoavst22 on 06/01/2020.
//

#ifndef ADVANCED1_HW3__DEFINEVARRIGHTCOMMAND_H_
#define ADVANCED1_HW3__DEFINEVARRIGHTCOMMAND_H_
#include "Command.h"
#include "SingletonObj.h"
//for code like: var x -> sim("path")
class DefineVarRightCommand: public Command {
	std::string name;
	std::string sim;

 public:
	DefineVarRightCommand(std::string varName, std::string simulator);
	void execute();
	virtual ~DefineVarRightCommand() {}
};
#endif //ADVANCED1_HW3__DEFINEVARRIGHTCOMMAND_H_
