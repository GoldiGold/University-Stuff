//
// Created by yoavst22 on 06/01/2020.
//

#ifndef ADVANCED1_HW3__SYMBOLTABLE_H_
#define ADVANCED1_HW3__SYMBOLTABLE_H_
using namespace std;
#include "ProgVar.cpp"
#include <string>
#include <map>
class SymbolTable {
  map<string, ProgVar*>* m;
 public:
  SymbolTable() {this->m = new map<string, ProgVar*>();}
  ~SymbolTable() {delete m;}

  void add(string name, double val, string simulator);
  ProgVar* get(string name) {return m->at(name);}

  double getVal(string name) {return m->at(name)->GetValue();}

  string getSim(string name) {return m->at(name)->GetSim();}
};
#endif //ADVANCED1_HW3__SYMBOLTABLE_H_