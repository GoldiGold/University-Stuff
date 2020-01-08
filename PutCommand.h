//
// Created by yoavst22 on 08/01/2020.
//

#ifndef ADVANCED1_HW3__PUTCOMMAND_H_
#define ADVANCED1_HW3__PUTCOMMAND_H_
#include "Command.h"
#include "SingletonObj.h"
#include <string>
class PutCommand: public Command {
  std::string exp;
  std::string name;

 public:
  PutCommand(std::string name1, std::string exp1){name = name1; exp = exp1;}
  int execute(std::string var);
  virtual ~PutCommand() {}
};
#endif //ADVANCED1_HW3__PUTCOMMAND_H_
