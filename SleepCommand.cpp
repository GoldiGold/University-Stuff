//
// Created by yoavst22 on 08/01/2020.
//


#include "SleepCommand.h"
int SleepCommand::execute(std::string var){
  double val = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();
  std::this_thread::sleep_for(std::chrono::milliseconds(int(val)));
}