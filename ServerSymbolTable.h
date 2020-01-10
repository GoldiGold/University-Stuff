//
// Created by חן גולדשטיין on 06/01/2020.
//

#ifndef ADVANCED1_HW3__SERVERSYMBOLTABLE_H_
#define ADVANCED1_HW3__SERVERSYMBOLTABLE_H_
#include "ProgVar.h"
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
#include "SymbolTable.h"
#include <iostream>
#include <vector>

class ServerSymbolTable {
	std::unordered_map<std::string, std::list<std::string> *> *m;
	std::vector<std::string> *insertion_order;
 public:
	ServerSymbolTable();
	virtual ~ServerSymbolTable();

	void add(std::string path, std::string varName);

//	std::list<std::string> *getList(std::string name);

	void updateAtSymbolTable(std::string path, double value, SymbolTable *symbol_table);

	std::unordered_map<std::string, std::list<std::string> *> *GetM() const;
	std::vector<std::string> *GetInsertionOrder() const;
//	double getVal(std::string name);
//
//	std::string getSim(std::string name);
};

#endif //ADVANCED1_HW3__SERVERSYMBOLTABLE_H_
