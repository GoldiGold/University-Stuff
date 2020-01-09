#include <iostream>
#include "ex1.h"
#include "SymbolTable.h"
#include "DefineVarRightCommand.h"
#include "DefineVarEqCommand.h"
#include "ServerSymbolTable.h"
#include "Condition.h"
#include "OpenServerCommand.h"
#include "ConnectClientCommand.h"
int main() {
////	std::cout << "bitchV2" << std::endl;
//	auto st = new SymbolTable();
////	std::cout << "bitchV3" << std::endl;
//	auto dvlc = new DefineVarRightCommand(st, "x", "/pathx");
////	std::cout << "bitchV4" << std::endl;
//	auto dvec = new DefineVarEqCommand(st, "y");
////	std::cout << "bitchV5" << std::endl;
//	dvlc->execute("");
////	std::cout << "bitchV6" << std::endl;
//	dvec->execute("");
////	std::cout << "bitchV7" << std::endl;
//	auto i = new Interpreter();
////	std::cout << "bitchV8" << std::endl;
//	i->setVariables(st->getVars());
////	std::cout << "bitchV9" << std::endl;
//	auto con = new Condition("x+y", "==", "7+x");
////	std::cout << "bitchV10" << std::endl;
//	std::cout /*<< "bitchV11"*/ << con->isTrue(i) /*<< "bitchV12"*/ << std::endl;
////	std::cout << "bitch" << std::endl;
//	delete st;
////  delete dvlc;
////  delete dvec;
int n;
#include <iostream>
#include "ex1.h"
#include "SymbolTable.h"
#include "DefineVarRightCommand.h"
#include "DefineVarEqCommand.h"
#include "ServerSymbolTable.h"
#include "Condition.h"
#include "IfCommand.h"
#include "SleepCommand.h"
#include "PrintCommand.h"
#include "PutCommand.h"
#include "WhileCommand.h"
#include "Parser.h"

		using namespace std;
//  auto wh = new WhileCommand("x","<=","5");
//  auto def = new DefineVarEqCommand("x", "0");
//  auto sleep = new SleepCommand("500");
//  auto p1 = new PrintCommand("x");
//  auto put = new PutCommand("x", "x+1");
//  wh->addCommand(p1);
//  wh->addCommand(sleep);
//  wh->addCommand(put);
//  def->execute("");
//  wh->execute("");
//  delete wh;
		auto l = new list<string>();
		l->push_back("var");
		l->push_back("x");
		l->push_back("=");
		l->push_back("3");
		l->push_back("while");
		l->push_back("x");
		l->push_back("<=");
		l->push_back("7");
		l->push_back("{");
		l->push_back("Sleep");
		l->push_back("x*500");
		l->push_back("Print");
		l->push_back("x");
		l->push_back("x");
		l->push_back("=");
		l->push_back("x+1");
		l->push_back("}");
		l->push_back("Print");
		l->push_back("\"it is done\"");
		Parser* p = new Parser(l);
		p->execute();

		return 0;

	auto command = new OpenServerCommand("5400");
	std::cout << "sockfd: " << command->GetSockfd() << " port: " << command->GetPort() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	command->execute("stuff");
	auto client = new ConnectClientCommand("127.0.0.1", "5402");
	client->execute("other stuff");
	SingletonObj::getInstance()->GetSymbolTable()->add("rpm", 5, "/engines/engine/rpm");
	SingletonObj::getInstance()->GetMessagesQueue()->push({"rpm", 3});
	SingletonObj::getInstance()->GetSymbolTable()->add("t", 0, "/controls/engines/engine/throttle");
	SingletonObj::getInstance()->GetMessagesQueue()->push({"t", 1});
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cin >> n;


	return 0;
}
