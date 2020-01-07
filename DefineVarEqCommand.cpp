//
// Created by yoavst22 on 07/01/2020.
//

#include "DefineVarEqCommand.h"
int DefineVarEqCommand::execute(std::string var){
	SingletonObj::getInstance()->GetSymbolTable()->add(name, val, "");
}