//
// Created by yoavst22 on 08/01/2020.
//

#ifndef ADVANCED1_HW3__PRINTCOMMAND_H_
#define ADVANCED1_HW3__PRINTCOMMAND_H_
#include "Command.h"
#include "SingletonObj.h"
#include <string>
class PrintCommand: public Command {
  std::string exp;

 public:
  PrintCommand(std::string exp1){exp = exp1;}
  int execute(std::string var);
  virtual ~PrintCommand() {}
};
#endif //ADVANCED1_HW3__PRINTCOMMAND_H_
