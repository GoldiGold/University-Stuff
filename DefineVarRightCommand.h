//
// Created by yoavst22 on 06/01/2020.
//

#ifndef ADVANCED1_HW3__DEFINEVARRIGHTCOMMAND_H_
#define ADVANCED1_HW3__DEFINEVARRIGHTCOMMAND_H_
#include "Command.h"
#include "SymbolTable.h"
class DefineVarRightCommand: public Command {
	SymbolTable* st;
	std::string name;
	std::string sim;

 public:
	DefineVarRightCommand(SymbolTable* symt, std::string varName, std::string simulator);
	int execute(std::string var);
	virtual ~DefineVarRightCommand() {}
};
#endif //ADVANCED1_HW3__DEFINEVARRIGHTCOMMAND_H_
