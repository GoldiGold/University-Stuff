//
// Created by yoavst22 on 07/01/2020.
//

#include "Condition.h"
bool Condition::isTrue() {
	//calculate the values:
	std::lock_guard<std::mutex> lk(SingletonObj::getInstance()->interpreter_mutex);
	double v1 = SingletonObj::getInstance()->GetInter()->interpret(exp1)->calculate();
	double v2 = SingletonObj::getInstance()->GetInter()->interpret(exp2)->calculate();
	if (!oper.compare("==")) {
		return (v1 == v2);
	} else if (!oper.compare("<=")) {
		return (v1 <= v2);
	} else if (!oper.compare(">=")) {
		return (v1 >= v2);
	} else if (!oper.compare("!=")) {
		return (v1 != v2);
	} else if (!oper.compare("<")) {
		return (v1 < v2);
	} else if (!oper.compare(">")) {
		return (v1 > v2);
	} else {
		throw "unvalid operator";
	}
}