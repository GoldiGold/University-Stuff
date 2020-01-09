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
#include "ex1.h"
#include <mutex>

class SingletonObj {
 private:
	/* Here will be the instance stored. */
	static SingletonObj *instance;
	bool global_has_server_opened_;
	SymbolTable *symbol_table_;
	ServerSymbolTable *server_symbol_table_;
	std::queue<std::pair<std::string, double>> *messages_queue_;
	bool should_stop_client_thread_;
	bool should_stop_server_thread_;
	bool have_connected_as_client_;
	Interpreter *singleInterpreter;
 public:
	std::mutex server_symbol_table_mutex;
	std::mutex symbol_table_mutex;
	std::mutex interpreter_mutex;
	std::mutex message_queue_mutex;
	std::mutex client_mutex;
	std::mutex thread_mutex;
	std::mutex has_opened_mutex;
	std::mutex connected_as_client_mutex;



 private:
	/* Private constructor to prevent instancing. */
	SingletonObj();

 public:
	bool IsShouldStopClientThread();
	void SetShouldStopClientThread(bool should_stop_client_thread);
	bool IsShouldStopServerThread();
	void SetShouldStopServerThread(bool should_stop_server_thread);
	bool IsHaveConnectedAsClient();
	void SetHaveConnectedAsClient(bool have_connected_as_client);
	bool IsGlobalHasServerOpened();
	void SetGlobalHasServerOpened(bool global_has_server_opened);
	SymbolTable *GetSymbolTable();
//	void SetSymbolTable(SymbolTable *symbol_table);
	ServerSymbolTable *GetServerSymbolTable();
//	void SetServerSymbolTable(ServerSymbolTable *server_symbol_table);
	std::queue<std::pair<std::string, double>> *GetMessagesQueue();
	void addMessagesQueue(std::string name, double val) {
		messages_queue_->push(std::pair<std::string, double>(name, val));
	}
	void SetMessagesQueue(std::queue<std::pair<std::string, double>> *messages_queue);
	Interpreter *GetInter() {
		singleInterpreter->setVariables(symbol_table_->getVars());
		return singleInterpreter;
	}
	/* Static access method. */
	static SingletonObj *getInstance();

};

#endif //ADVANCED1_HW3_SINGLETONOBJ_H_
