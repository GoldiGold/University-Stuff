//
// Created by yoavst22 on 06/01/2020.
//

#include "DefineVarCommand.h"
int DefinrVarCommand::execute(string var){
  st->add(name, val, sim);
  //add to server symbol table
}
DefinrVarCommand::DefinrVarCommand(SymbolTable* symt, string varName, double value, string simulator){
  st = symt;
  name = varName;
  val = value;
  sim = simulator;
}