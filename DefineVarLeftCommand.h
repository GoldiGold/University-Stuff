//
// Created by yoavst22 on 07/01/2020.
//

#ifndef NEW__DEFINEVARLEFTCOMMAND_H_
#define NEW__DEFINEVARLEFTCOMMAND_H_
#include "Command.h"
#include "SymbolTable.h"
#include "ServerSymbolTable.h"

class DefineVarLeftCommand: public Command {
  SymbolTable* st;
  ServerSymbolTable* sst;
  string name;
  string sim;

 public:
  DefineVarLeftCommand(SymbolTable* symt, ServerSymbolTable* ssymt, string varName, string simulator);
  int execute(string var);
  virtual ~DefineVarLeftCommand() {delete st; delete sst;}
};
#endif //NEW__DEFINEVARLEFTCOMMAND_H_
