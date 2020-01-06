//
// Created by yoavst22 on 29/12/2019.
//

#include "SymbolTable.h"
void SymbolTable::add(string name, double val, string simulator) {
  m->insert(pair<string, ProgVar*>(name, new ProgVar(val, simulator)));
}