//
// Created by yoavst22 on 08/01/2020.
//

#ifndef ADVANCED1_HW3__WHILECOMMAND_H_
#define ADVANCED1_HW3__WHILECOMMAND_H_
#include "Command.h"
#include "Condition.h"
#include <string>
#include <list>
class WhileCommand: public Command {
  Condition* con;
  std::list<Command*>* commands;

 public:
  WhileCommand(std::string exp1, std::string oper, std::string exp2);
  int execute(std::string var);
  void addCommand(Command* com) {commands->push_back(com);}
  virtual ~WhileCommand() {delete con; delete commands;}
};
#endif //ADVANCED1_HW3__WHILECOMMAND_H_
