//
// Created by yoavst22 on 07/01/2020.
//

#include "DefineVarEqCommand.h"
int DefineVarEqCommand::execute(string var){
  this->st->add(name, val, "");
}