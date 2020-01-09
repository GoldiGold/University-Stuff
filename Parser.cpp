//
// Created by yoavst22 on 09/01/2020.
//

#include "Parser.h"
#include <typeinfo>

Parser::Parser(std::list<std::string> *l) {
	using namespace std;
	strList = l;
	commands = new list<Command *>();
	it = strList->begin();
	while (it != strList->end()) {//while we not in the end of the list
		commands->push_back(createCom());//add the command from the function
		it++;//move one step forward
	}
}

Command *Parser::createCom() {//create one command
	using namespace std;
	if (!(*it).compare("openDataServer")) {
		it++;
		auto c = new OpenServerCommand(*it);
		return c;
	} else if (!(*it).compare("connectControlClient")) {
		string ip = (*(++it));
		ip = ip.substr(1,ip.length()-2);
		string port = *(++it);
		auto c = new ConnectClientCommand(ip.c_str(),port, ip.length());
		return c;
	} else if (!(*it).compare("Print")) {//print
		it++;
		auto c = new PrintCommand(*it);//*it is the parameter of print
		return c;
	} else if (!(*it).compare("Sleep")) {//sleep
		it++;
		auto c = new SleepCommand(*it);
		return c;
	} else if (!(*it).compare("var")) {//define var commands
		string var = *(++it);
		it++;
		if (!(*it).compare("->")) {//right
			it++;
			string sim = *(++it);
			auto c = new DefineVarRightCommand(var, sim.substr(1, sim.length() - 2));
			return c;
		} else if (!(*it).compare("<-")) {//left
			it++;
			string sim = *(++it);
			auto c = new DefineVarLeftCommand(var, sim.substr(1, sim.length() - 2));
			return c;
		} else if (!(*it).compare("=")) {//equal
			string exp = *(++it);
			auto c = new DefineVarEqCommand(var, exp);
			return c;
		} else {//undefined command
			throw "invalid define var command";
		}
	} else if (!(*it).compare("if")) {
		string exp1 = *(++it);
		string oper = *(++it);
		string exp2 = *(++it);
		auto c = new IfCommand(exp1, oper, exp2);
		it++;
		if (!(*it).compare("{")) {
			it++;
			while ((*it).compare("}")) {
				Command *ic = createCom();//inner command
				c->addCommand(ic);
				it++;
			}
			return c;
		} else {
			throw "invalid if command";
		}
	} else if (!(*it).compare("while")) {
		string exp1 = *(++it);
		string oper = *(++it);
		string exp2 = *(++it);
		auto c = new WhileCommand(exp1, oper, exp2);
		it++;
		if (!(*it).compare("{")) {
			it++;
			while ((*it).compare("}")) {
				Command *ic = createCom();//inner command
				c->addCommand(ic);
				it++;
			}
			return c;
		} else {
			throw "invalid while command";
		}
	} else {
		string var = *it;
		it++;
		if (!(*it).compare("=")) {
			string exp = *(++it);
			auto c = new PutCommand(var, exp);
			return c;
		} else {
			throw "invalid command";
		}
	}
}

void Parser::execute() {
	std::string s;

	for (Command *com: *commands) {
		// if the command is a Connect Client Command, then we wait for an established connection.
//		std::cout << "is: " << (typeid(*com) == typeid(ConnectClientCommand)) << std::endl;
		if (typeid(*com) == typeid(ConnectClientCommand)) {
			com->execute("");
			std::cout << "finished creating client VVVVVV" << std::endl;

			while (!SingletonObj::getInstance()->IsHaveConnectedAsClient()) {
				// do nothing, just wait for the client to connect to the simulator.
			}

			std::cout << "finished creating client" << std::endl;
		} else {
			com->execute("");
		}
	}
	SingletonObj::getInstance()->SetShouldStopServerThread(true);
	SingletonObj::getInstance()->SetShouldStopClientThread(true);
	std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}
