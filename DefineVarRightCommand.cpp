
//
// Created by yoavst22 on 06/01/2020.
//

#include "DefineVarRightCommand.h"
int DefineVarRightCommand::execute(std::string var){
	this->st->add(name, 0, sim);
	return 1;
}
DefineVarRightCommand::DefineVarRightCommand(SymbolTable* symt, std::string varName, std::string simulator){
	st = symt;
	name = varName;
	sim = simulator;
}