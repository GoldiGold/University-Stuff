//
// Created by חן גולדשטיין on 07/01/2020.
//

#ifndef ADVANCED1_HW3_SINGLETONOBJ_H_
#define ADVANCED1_HW3_SINGLETONOBJ_H_

#include <iostream>
#include "ServerSymbolTable.h"
#include "SymbolTable.h"
#include <string>
#include <queue>

class SingletonObj {
 private:
	/* Here will be the instance stored. */
	static SingletonObj *instance;
	bool global_has_server_opened_;
	SymbolTable *symbol_table_;
	ServerSymbolTable *server_symbol_table_;
	std::queue<std::pair<std::string, int>> *messages_queue_;

	/* Private constructor to prevent instancing. */
	SingletonObj();

 public:
	bool IsGlobalHasServerOpened();
	void SetGlobalHasServerOpened(bool global_has_server_opened);
	SymbolTable *GetSymbolTable();
	void SetSymbolTable(SymbolTable *symbol_table);
	ServerSymbolTable *GetServerSymbolTable();
	void SetServerSymbolTable(ServerSymbolTable *server_symbol_table);
	std::queue<std::pair<std::string, int>> *GetMessagesQueue();
	void SetMessagesQueue(std::queue<std::pair<std::string, int>> *messages_queue);
	/* Static access method. */
	static SingletonObj *getInstance();
};

#endif //ADVANCED1_HW3_SINGLETONOBJ_H_
