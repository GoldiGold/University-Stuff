//
// Created by yoavst22 on 07/01/2020.
//
#include "DefineVarLeftCommand.h"
DefineVarLeftCommand::DefineVarLeftCommand(std::string varName, std::string simulator) {
	name = varName;
	sim = simulator;
}
int DefineVarLeftCommand::execute(std::string var){
  SingletonObj::getInstance()->GetSymbolTable()->add(name, 0, "");
  SingletonObj::getInstance()->GetServerSymbolTable()->add(sim, name);
  return 0;
}