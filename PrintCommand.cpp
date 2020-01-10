//
// Created by yoavst22 on 08/01/2020.
//

#include "PrintCommand.h"
void PrintCommand::execute() {
    bool in_map = false;
    if (exp[0] == '"' && exp[exp.length() - 1] == '"') {
        std::cout << exp.substr(1, exp.length() - 2) << std::endl;
    } else {
        double val = 0; //default
        SingletonObj::getInstance()->symbol_table_mutex.lock();
        if (SingletonObj::getInstance()->GetSymbolTable()->getMap()->find(exp)
            != SingletonObj::getInstance()->GetSymbolTable()->getMap()->end()) {
            val = SingletonObj::getInstance()->GetSymbolTable()->getMap()->at(exp)->GetValue();
            SingletonObj::getInstance()->symbol_table_mutex.unlock();
            //			if ((exp.compare("rpm"))) {
            //				std::cout << val << std::endl;
            //			}
            in_map = true;
        }
        // if hasn't entered the if:
        SingletonObj::getInstance()->symbol_table_mutex.unlock();
        
        if (!in_map) {
            SingletonObj::getInstance()->interpreter_mutex.lock();
            
            val = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();

            SingletonObj::getInstance()->interpreter_mutex.unlock();
        }
            std::cout << val << std::endl;
        
    }
}
