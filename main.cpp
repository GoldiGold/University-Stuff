#include <iostream>
#include "ex1.h"
#include "SymbolTable.h"
#include "DefineVarRightCommand.h"
#include "DefineVarEqCommand.h"
#include "ServerSymbolTable.h"
#include "Condition.h"
int main() {
  auto st = new SymbolTable();
  auto dvlc = new DefineVarRightCommand(st, "x", "/pathx");
  auto dvec = new DefineVarEqCommand(st,"y", 7);
  dvlc->execute("");
  dvec->execute("");

  auto i = new Interpreter();
  i->setVariables(st->getVars());
  auto con = new Condition("x+y","==","7+x");
  cout<<con->isTrue(i);
  delete st;
//  delete dvlc;
//  delete dvec;
  return 0;
}
