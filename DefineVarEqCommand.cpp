//
// Created by yoavst22 on 07/01/2020.
//

#include "DefineVarEqCommand.h"
void DefineVarEqCommand::execute() {
	SingletonObj::getInstance()->interpreter_mutex.lock();
	double val = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();
	SingletonObj::getInstance()->interpreter_mutex.unlock();

	SingletonObj::getInstance()->symbol_table_mutex.lock();
	SingletonObj::getInstance()->GetSymbolTable()->add(name, val, "");
	SingletonObj::getInstance()->symbol_table_mutex.unlock();
}