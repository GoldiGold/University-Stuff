//
// Created by yoavst22 on 07/01/2020.
//

#ifndef ADVANCED1_HW3__DEFINEVAREQCOMMAND_H_
#define ADVANCED1_HW3__DEFINEVAREQCOMMAND_H_
#include "Command.h"
#include "SymbolTable.h"
#include "SingletonObj.h"
#include <string>
class DefineVarEqCommand: public Command {
	std::string name;
	double val;

 public:
	DefineVarEqCommand(std::string varName, double value){name = varName; val = value;}
	int execute(std::string var);
	virtual ~DefineVarEqCommand() {}
};
#endif //ADVANCED1_HW3__DEFINEVAREQCOMMAND_H_
