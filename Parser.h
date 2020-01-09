//
// Created by yoavst22 on 09/01/2020.
//

#ifndef ADVANCED1_HW3__PARSER_H_
#define ADVANCED1_HW3__PARSER_H_
#include <list>
#include <string>
#include "Command.h"
#include "ConnectClientCommand.h"
#include "DefineVarLeftCommand.h"
#include "DefineVarRightCommand.h"
#include "DefineVarEqCommand.h"
#include "IfCommand.h"
#include "OpenServerCommand.h"
#include "PrintCommand.h"
#include "PutCommand.h"
#include "SleepCommand.h"
#include "IfCommand.h"
#include "WhileCommand.h"
//this class take the strings list from the lexer and create list of commands
class Parser {
  std::list<std::string>* strList;
  std::list<Command*>* commands;
  std::list<std::string>::iterator it;
 public:
  Parser(std::list<std::string>* l);
  ~Parser() {delete strList; delete commands;}
  void execute();
 private://for use inside the class
  //this func creates one command and return the updated iterator
  Command* createCom();
};
#endif //ADVANCED1_HW3__PARSER_H_
