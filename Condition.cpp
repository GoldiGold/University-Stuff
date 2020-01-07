//
// Created by yoavst22 on 07/01/2020.
//

#include "Condition.h"
bool Condition::isTrue(Interpreter* i){
  double v1 = i->interpret(exp1)->calculate();//calculate the values
  double v2 = i->interpret(exp2)->calculate();
  if(!oper.compare("==")) {
    return (v1 == v2);
  } else if(!oper.compare("<=")) {
    return (v1 <= v2);
  } else if(!oper.compare(">=")) {
    return (v1 >= v2);
  } else if(!oper.compare("!=")) {
    return (v1 != v2);
  } else if(!oper.compare("<")) {
    return (v1 < v2);
  } else if(!oper.compare(">")) {
    return (v1 > v2);
  } else {
    throw "unvalid operator";
  }
}