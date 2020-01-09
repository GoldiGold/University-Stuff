//
// Created by yoavst22 on 07/01/2020.
//

#ifndef ADVANCED1_HW3__CONDITION_H_
#define ADVANCED1_HW3__CONDITION_H_
#include "ex1.h"
#include "SingletonObj.h"
//this class is the base for if and while commands
class Condition {
  std::string exp1;
  std::string exp2;
  std::string oper;
 public:
  Condition(std::string expression1, std::string operat, std::string expression2){
    exp1 = expression1;
    exp2 = expression2;
    oper = operat;
  }
  bool isTrue();//is the contidion true?

};
#endif //ADVANCED1_HW3__CONDITION_H_
