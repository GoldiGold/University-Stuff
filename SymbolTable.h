//
// Created by yoavst22 on 06/01/2020.
//

#ifndef ADVANCED1_HW3__SYMBOLTABLE_H_
#define ADVANCED1_HW3__SYMBOLTABLE_H_

#include "ProgVar.h"
#include <string>
#include <map>
class SymbolTable {
	std::map<std::string, ProgVar *> *m;
	vars = new map<std::string, double>();
 public:
	SymbolTable() { this->m = new std::map<std::string, ProgVar *>(); }
	~SymbolTable() { delete m; delete vars;}

	void add(std::string name, double val, std::string simulator);
	ProgVar *get(std::string name) { return m->at(name); }

	double getVal(std::string name) { return m->at(name)->GetValue(); }

	void setVal(std::string name, double val) { 
		m->at(name)->SetValue(val);
		vars->insert(std::pair<std::string, double>(name, val));
	}

	std::string getSim(std::string name) { return m->at(name)->GetSim(); }

	std::map<std::string, ProgVar *> *getMap() { return this->m; }
	std::map<std::string, double>* getVars() { return vars;}
};

#endif //ADVANCED1_HW3__SYMBOLTABLE_H_
