//
// Created by חן גולדשטיין on 06/01/2020.
//

#ifndef ADVANCED1_HW3__SERVERSYMBOLTABLE_H_
#define ADVANCED1_HW3__SERVERSYMBOLTABLE_H_
#include "ProgVar.h"
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include "SymbolTable.h"

class ServerSymbolTable {
	std::map<std::string, std::list<std::string> *> *m;
 public:
	ServerSymbolTable();
	virtual ~ServerSymbolTable();

	void add(std::string path, std::string varName);

	std::list<std::string>* getList(std::string name);

	void updateAtSymbolTable(std::string path, double value, SymbolTable* symbol_table);

//	double getVal(std::string name);
//
//	std::string getSim(std::string name);
};

#endif //ADVANCED1_HW3__SERVERSYMBOLTABLE_H_
