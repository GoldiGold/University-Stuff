//
// Created by yoavst22 on 29/12/2019.
//

#include "SymbolTable.h"
void SymbolTable::add(std::string name, double val, std::string simulator) {
  m->insert(std::pair<std::string, ProgVar*>(name, new ProgVar(val, simulator)));
}