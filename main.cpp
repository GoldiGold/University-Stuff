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
#include "PutCommand.h"
#include "WhileCommand.h"
int main() {
  using namespace std;
  auto wh = new WhileCommand("x","<=","5");
  auto def = new DefineVarEqCommand("x", "0");
  auto sleep = new SleepCommand("500");
  auto p1 = new PrintCommand("x");
  auto put = new PutCommand("x", "x+1");
  wh->addCommand(p1);
  wh->addCommand(sleep);
  wh->addCommand(put);

  def->execute("");
  wh->execute("");
//  cout<< SingletonObj::getInstance()->GetSymbolTable()->getVal("x")<<endl;

  return 0;
}
