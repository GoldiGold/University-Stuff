//
// Created by yoavst22 on 06/01/2020.
//

#ifndef FLIGHTSIMULATOR__DEFINEVARCOMMAND_H_
#define FLIGHTSIMULATOR__DEFINEVARCOMMAND_H_
#include "Command.h"
#include "SymbolTable.h"
class DefineVarRightCommand: public Command {
  SymbolTable* st;
  string name;
  string sim;

 public:
  DefineVarRightCommand(SymbolTable* symt, string varName, string simulator);
  int execute(string var);
  virtual ~DefineVarRightCommand() {delete st;}
};
#endif //FLIGHTSIMULATOR__DEFINEVARCOMMAND_H_
