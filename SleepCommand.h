//
// Created by yoavst22 on 08/01/2020.
//

#ifndef ADVANCED1_HW3__SLEEPCOMMAND_H_
#define ADVANCED1_HW3__SLEEPCOMMAND_H_
#include "Command.h"
#include "SingletonObj.h"
#include <string>
#include <thread>
#include <chrono>
class SleepCommand: public Command {
  std::string exp;

 public:
  SleepCommand(std::string exp1){exp = exp1;}
  int execute(std::string var);
  virtual ~SleepCommand() {}
};
#endif //ADVANCED1_HW3__SLEEPCOMMAND_H_
