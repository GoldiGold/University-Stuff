//
// Created by yoavst22 on 07/01/2020.
//
#include "DefineVarLeftCommand.h"
DefineVarLeftCommand::DefineVarLeftCommand(std::string varName, std::string simulator) {
	name = varName;
//	std::cout << "define var left name: " << name << std::endl;
	sim = simulator;
//	std::cout << "define var left path: " << sim << std::endl;

}
void DefineVarLeftCommand::execute() {
	SingletonObj::getInstance()->symbol_table_mutex.lock();
	SingletonObj::getInstance()->GetSymbolTable()->add(name, 0, "");
	SingletonObj::getInstance()->symbol_table_mutex.unlock();

	SingletonObj::getInstance()->server_symbol_table_mutex.lock();
	SingletonObj::getInstance()->GetServerSymbolTable()->add(sim, name);
	SingletonObj::getInstance()->server_symbol_table_mutex.unlock();
}