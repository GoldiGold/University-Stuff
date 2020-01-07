
//
// Created by yoavst22 on 06/01/2020.
//

#include "DefineVarRightCommand.h"
int DefineVarRightCommand::execute(std::string var){
  SingletonObj::getInstance()->GetSymbolTable()->add(name, 0, sim);
	return 1;
}
DefineVarRightCommand::DefineVarRightCommand(std::string varName, std::string simulator){
	name = varName;
	sim = simulator;
}