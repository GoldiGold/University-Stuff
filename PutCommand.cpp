//
// Created by yoavst22 on 08/01/2020.
//

#include "PutCommand.h"
int PutCommand::execute(std::string var){
  double val = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();
  SingletonObj::getInstance()->GetSymbolTable()->setVal(name, val);
  std::string sim = SingletonObj::getInstance()->GetSymbolTable()->getSim(name);
  if(sim.length() > 0) {
    SingletonObj::getInstance()->addMessagesQueue(name, val);
  }
}