//
// Created by yoavst22 on 08/01/2020.
//

#include "PrintCommand.h"
int PrintCommand::execute(std::string var) {
  if(exp[0]=='"' && exp[exp.length()-1]=='"'){
    std::cout<<exp.substr(1, exp.length()-2)<<std::endl;
  } else {
  	SingletonObj::getInstance()->interpreter_mutex.lock();
    double val = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();
    SingletonObj::getInstance()->interpreter_mutex.unlock();
    std::cout<<val<<std::endl;
  }
}