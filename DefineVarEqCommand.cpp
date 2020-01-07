//
// Created by yoavst22 on 07/01/2020.
//

#include "DefineVarEqCommand.h"
int DefineVarEqCommand::execute(std::string var){
  double val = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();
  SingletonObj::getInstance()->GetSymbolTable()->add(name, val, "");
}