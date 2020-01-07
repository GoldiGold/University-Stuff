//
// Created by yoavst22 on 07/01/2020.
//

#ifndef ADVANCED1_HW3__DEFINEVARLEFTCOMMAND_H_
#define ADVANCED1_HW3__DEFINEVARLEFTCOMMAND_H_
#include "Command.h"
#include "SymbolTable.h"
#include "ServerSymbolTable.h"

class DefineVarLeftCommand: public Command {
	SymbolTable* st;
	ServerSymbolTable* sst;
	std::string name;
	std::string sim;

 public:
	DefineVarLeftCommand(SymbolTable* symt, ServerSymbolTable* ssymt, std::string varName, std::string simulator);
	int execute(std::string var);
	virtual ~DefineVarLeftCommand() {delete st; delete sst;}
};
#endif //ADVANCED1_HW3__DEFINEVARLEFTCOMMAND_H_