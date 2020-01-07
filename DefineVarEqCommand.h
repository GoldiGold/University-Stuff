//
// Created by yoavst22 on 07/01/2020.
//

#ifndef ADVANCED1_HW3__DEFINEVAREQCOMMAND_H_
#define ADVANCED1_HW3__DEFINEVAREQCOMMAND_H_
using namespace std;
#include "Command.h"
#include "SymbolTable.h"
#include <string>
class DefineVarEqCommand: public Command {
  SymbolTable* st;
  string name;
  double val;

 public:
  DefineVarEqCommand(SymbolTable* symt, string varName, double value){st = symt; name = varName; val = value;}
  int execute(string var);
  virtual ~DefineVarEqCommand(){delete st;}
};
#endif //ADVANCED1_HW3__DEFINEVAREQCOMMAND_H_
