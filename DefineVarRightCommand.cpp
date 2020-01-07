//
// Created by yoavst22 on 06/01/2020.
//

#include "DefineVarRightCommand.h"
int DefineVarRightCommand::execute(string var){
  this->st->add(name, 0, sim);
}
DefineVarRightCommand::DefineVarRightCommand(SymbolTable* symt, string varName, string simulator){
  st = symt;
  name = varName;
  sim = simulator;
}