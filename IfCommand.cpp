//
// Created by yoavst22 on 08/01/2020.
//

#include "IfCommand.h"
IfCommand::IfCommand(std::string exp1, std::string oper, std::string exp2){
  con = new Condition(exp1, oper, exp2);
  commands = new std::list<Command*>();
}
void IfCommand::execute(){
  if(con->isTrue()) {
    for(Command* c: *commands) {
      c->execute();
    }
  }
}