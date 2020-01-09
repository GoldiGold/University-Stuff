//
// Created by yoavst22 on 08/01/2020.
//

#ifndef ADVANCED1_HW3__IFCOMMAND_H_
#define ADVANCED1_HW3__IFCOMMAND_H_
#include "Command.h"
#include "Condition.h"
#include <string>
#include <list>
class IfCommand: public Command {
  Condition* con;//condition
  std::list<Command*>* commands;//commands to do if the condition is true

 public:
  IfCommand(std::string exp1, std::string oper, std::string exp2);
  int execute(std::string var);
  void addCommand(Command* com) {commands->push_back(com);}
  virtual ~IfCommand() {delete con; delete commands;}
};
#endif //ADVANCED1_HW3__IFCOMMAND_H_
