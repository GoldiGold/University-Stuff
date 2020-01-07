//
// Created by yoavst22 on 06/01/2020.
//

#ifndef FLIGHTSIMULATOR__DEFINEVARCOMMAND_H_
#define FLIGHTSIMULATOR__DEFINEVARCOMMAND_H_
#include "Command.h"
#include "SymbolTable.h"
class DefineVarCommand: public Command {
  SymbolTable* st;
  //server symbol table
  string name;
  double val;
  string sim;

 public:
  DefineVarCommand(SymbolTable* symt, string varName, double value, string simulator);
  int execute(string var);
  virtual ~DefineVarCommand() {delete st;}
};
#endif //FLIGHTSIMULATOR__DEFINEVARCOMMAND_H_
