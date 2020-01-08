#include <iostream>
#include "ex1.h"
#include "SymbolTable.h"
#include "DefineVarRightCommand.h"
#include "DefineVarEqCommand.h"
#include "ServerSymbolTable.h"
#include "Condition.h"
#include "IfCommand.h"
#include "SleepCommand.h"
#include "PrintCommand.h"
int main() {
  using namespace std;
  auto ic = new IfCommand("4","<=","5");
  auto dvec2 = new DefineVarEqCommand("x", "5");
  auto sleep = new SleepCommand("5000");
  auto p1 = new PrintCommand("777");
  ic->addCommand(dvec2);
  ic->addCommand(p1);
  ic->addCommand(sleep);
  ic->addCommand(p1);


  ic->execute("");
  cout<< SingletonObj::getInstance()->GetSymbolTable()->getVal("x")<<endl;

//  auto i = new Interpreter();
//  i->setVariables(st->getVars());


  return 0;
}
