//
// Created by yoavst22 on 29/12/2019.
//

using namespace std;
#include "ProgVar.cpp"
#include <string>
#include <map>
class SymbolTable {
  map<string, ProgVar*>* m;
 public:
  SymbolTable() {
    this->m = new map<string, ProgVar*>();
  }
  ~SymbolTable() {
    delete m;
  }

  void add(string name, double val, string simulator) {
    m->insert(pair<string, ProgVar*>(name, new ProgVar(val, simulator)));
  }

  ProgVar* get(string name) {
    return m->at(name);
  }

  double getVal(string name) {
    return m->at(name)->GetValue();
  }

  string getSim(string name) {
    return m->at(name)->GetSim();
  }
};
