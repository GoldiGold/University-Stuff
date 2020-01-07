//
// Created by yoavst22 on 07/01/2020.
//
#include "DefineVarLeftCommand.h"
DefineVarLeftCommand::DefineVarLeftCommand(SymbolTable* symt, ServerSymbolTable* ssymt,
    string varName, string simulator){
  st = symt;
  sst = ssymt;
  name = varName;
  sim = simulator;
}
int DefineVarLeftCommand::execute(string var){
  this->st->add(name, 0, nullptr);
  this->sst->add(sim, name);
  return 0;
}