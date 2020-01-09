//
// Created by yoavst22 on 08/01/2020.
//


#include "SleepCommand.h"
int SleepCommand::execute(std::string var) {
	SingletonObj::getInstance()->interpreter_mutex.lock();
	double val = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();
	SingletonObj::getInstance()->interpreter_mutex.unlock();

	std::this_thread::sleep_for(std::chrono::milliseconds(int(val)));
}