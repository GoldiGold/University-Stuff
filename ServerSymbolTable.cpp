//
// Created by חן גולדשטיין on 06/01/2020.
//

#include "ServerSymbolTable.h"

ServerSymbolTable::ServerSymbolTable() {
	this->m = new std::map<std::string, std::list<std::string> *>();
}
ServerSymbolTable::~ServerSymbolTable() {
	delete this->m;
}

void ServerSymbolTable::add(std::string path, std::string varName) {
	using namespace std;
	if (this->m->find(path) != this->m->end()) {
		list<std::string> *list_at_path = this->m->at(path);
		// if the variable doesn't exist then we need to do add it. If it exist we aren't going to add it again.
		if (std::find(list_at_path->begin(), list_at_path->end(), varName) == list_at_path->end()) {
			this->m->at(path)->push_front(varName);
		}
	} else {
		auto insert = new std::list<std::string>;
		insert->push_front(varName);
		this->m->insert({path, insert});
	}
}

void ServerSymbolTable::updateAtSymbolTable(std::string path, double value, SymbolTable *symbol_table) {
	using namespace std;
	// If this path exists
	if (this->m->find(path) != this->m->end()) {
		list<std::string> *list_at_path = this->m->at(path);
		for (auto iterator = list_at_path->begin(); iterator != list_at_path->end(); ++iterator) {
			//If the value exist in the symbol_table, otherwise there is nothing to update.
			if (symbol_table->getMap()->find(*iterator) != symbol_table->getMap()->end()) {
				symbol_table->setVal(*iterator, value);
			}
		}
	}
}


//std::list<std::string>* ServerSymbolTable::getList(std::string path) {
//	return this->m->at(path);
//}
//
//double ServerSymbolTable::getVal(std::string name) {
//	return m->at(name).GetValue();
//}
//
//std::string ServerSymbolTable::getSim(std::string name) {
//	return m->at(name).GetSim();
//}