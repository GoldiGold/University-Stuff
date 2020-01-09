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
#include "Parser.h"
int main() {
  using namespace std;
//  auto wh = new WhileCommand("x","<=","5");
//  auto def = new DefineVarEqCommand("x", "0");
//  auto sleep = new SleepCommand("500");
//  auto p1 = new PrintCommand("x");
//  auto put = new PutCommand("x", "x+1");
//  wh->addCommand(p1);
//  wh->addCommand(sleep);
//  wh->addCommand(put);
//  def->execute("");
//  wh->execute("");
//  delete wh;
  auto l = new list<string>();
  l->push_back("var");
  l->push_back("x");
  l->push_back("=");
  l->push_back("3");
  l->push_back("while");
  l->push_back("x");
  l->push_back("<=");
  l->push_back("7");
  l->push_back("{");
  l->push_back("Sleep");
  l->push_back("x*500");
  l->push_back("Print");
  l->push_back("x");
  l->push_back("x");
  l->push_back("=");
  l->push_back("x+1");
  l->push_back("}");
  l->push_back("Print");
  l->push_back("\"it is done\"");
  Parser* p = new Parser(l);
  p->execute();

  return 0;
}
