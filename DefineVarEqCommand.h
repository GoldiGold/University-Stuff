//
// Created by yoavst22 on 07/01/2020.
//

#ifndef ADVANCED1_HW3__DEFINEVAREQCOMMAND_H_
#define ADVANCED1_HW3__DEFINEVAREQCOMMAND_H_
#include "Command.h"
#include "SingletonObj.h"
#include <string>
//for code like: var x = 5
//define variable indipendent wuth the simulator
class DefineVarEqCommand: public Command {
	std::string name;//var name
	std::string exp;//var initial value

 public:
	DefineVarEqCommand(std::string varName, std::string exp1){name = varName; exp=exp1;}
	void execute();
	virtual ~DefineVarEqCommand() {}
};
#endif //ADVANCED1_HW3__DEFINEVAREQCOMMAND_H_
