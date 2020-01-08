//
// Created by yoavst22 on 08/01/2020.
//

#include "WhileCommand.h"
WhileCommand::WhileCommand(std::string exp1, std::string oper, std::string exp2){
  con = new Condition(exp1, oper, exp2);
  commands = new std::list<Command*>();
}
int WhileCommand::execute(std::string var){
  while(con->isTrue()) {
    for(Command* c: *commands) {
      c->execute("");
    }
  }
}