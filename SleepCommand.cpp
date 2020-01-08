//
// Created by yoavst22 on 08/01/2020.
//

#include "SleepCommand.h"
int SleepCommand::execute(std::string var){
  double val = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();
  sleep(val/1000.0);
}