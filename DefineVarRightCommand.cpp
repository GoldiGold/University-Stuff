
//
// Created by yoavst22 on 06/01/2020.
//

#include "DefineVarRightCommand.h"
void DefineVarRightCommand::execute() {
	SingletonObj::getInstance()->symbol_table_mutex.lock();
	SingletonObj::getInstance()->GetSymbolTable()->add(name, 0, sim);
	SingletonObj::getInstance()->symbol_table_mutex.unlock();
}
DefineVarRightCommand::DefineVarRightCommand(std::string varName, std::string simulator) {
	name = varName;
	sim = simulator;
}