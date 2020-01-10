//
// Created by yoavst22 on 29/12/2019.
//

#include <iostream>
#include "SymbolTable.h"
void SymbolTable::add(std::string name, double val, std::string simulator) {
	m->insert({name, new ProgVar(val, simulator)});
	vars->insert({name, val});
}
void SymbolTable::setVal(std::string name, double val) {
	m->at(name)->SetValue(val);
//	auto it = ;
	if (vars->find(name) != vars->end()) {
		vars->at(name) = val;
	}
}
