//
// Created by yoavst22 on 08/01/2020.
//

#include "PrintCommand.h"
int PrintCommand::execute(std::string var) {
	if (exp[0] == '"' && exp[exp.length() - 1] == '"') {
		std::cout << exp.substr(1, exp.length() - 2) << std::endl;
	} else {
		double val;
		SingletonObj::getInstance()->symbol_table_mutex.lock();
		if (SingletonObj::getInstance()->GetSymbolTable()->getMap()->find(exp)
			!= SingletonObj::getInstance()->GetSymbolTable()->getMap()->end()) {
			val = SingletonObj::getInstance()->GetSymbolTable()->getMap()->at(exp)->GetValue();
			SingletonObj::getInstance()->symbol_table_mutex.unlock();
//			if ((exp.compare("rpm"))) {
				std::cout << val << std::endl;
//			}
			return 1;
		}
		// if hasn't entered the if:
		SingletonObj::getInstance()->symbol_table_mutex.unlock();

		SingletonObj::getInstance()->interpreter_mutex.lock();

//		std::cout << "the expression is: " << exp << std::endl;
		val = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();
//		std::cout << "the value is: " << val << std::endl;

		SingletonObj::getInstance()->interpreter_mutex.unlock();
		std::cout << val << std::endl;
	}
}