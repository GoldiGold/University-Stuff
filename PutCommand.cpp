//
// Created by yoavst22 on 08/01/2020.
//

#include "PutCommand.h"
int PutCommand::execute(std::string var) {
	SingletonObj::getInstance()->interpreter_mutex.lock();
	double val = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();
	SingletonObj::getInstance()->interpreter_mutex.unlock();

	SingletonObj::getInstance()->symbol_table_mutex.lock();
	SingletonObj::getInstance()->GetSymbolTable()->setVal(name, val);
	std::string sim = SingletonObj::getInstance()->GetSymbolTable()->getSim(name);
	SingletonObj::getInstance()->symbol_table_mutex.unlock();

	if (sim.length() > 0) {
		SingletonObj::getInstance()->message_queue_mutex.lock();
		SingletonObj::getInstance()->addMessagesQueue(name, val);
		SingletonObj::getInstance()->message_queue_mutex.unlock();

	}
}