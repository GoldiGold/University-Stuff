//
// Created by yoavst22 on 29/12/2019.
//

#include "SymbolTable.h"
void SymbolTable::add(std::string name, double val, std::string simulator) {
  m->insert(std::pair<std::string, ProgVar*>(name, new ProgVar(val, simulator)));
  vars->insert(std::pair<std::string, double>(name, val));
}
void SymbolTable::setVal(std::string name, double val) {
  m->at(name)->SetValue(val);
  auto it = vars->find(name);
  if(it != vars->end()){
    it->second = val;
  }
}
