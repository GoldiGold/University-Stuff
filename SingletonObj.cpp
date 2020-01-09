//
// Created by חן גולדשטיין on 07/01/2020.
//

#include "SingletonObj.h"
/* Null, because instance will be initialized on demand. */
SingletonObj *SingletonObj::instance = nullptr;

SingletonObj *SingletonObj::getInstance() {
	if (instance == nullptr) {
		instance = new SingletonObj();
	}

	return instance;
}

SingletonObj::SingletonObj() {
	this->global_has_server_opened_ = false;
	this->symbol_table_ = new SymbolTable();
	this->server_symbol_table_ = new ServerSymbolTable();
	this->messages_queue_ = new std::queue<std::pair<std::string, double>>();
	this->should_stop_client_thread_ = false;
	this->should_stop_server_thread_ = false;
//	this->did_created_client = false;
	this->have_connected_as_client_ = false;
	this->singleInterpreter = new Interpreter();

}
bool SingletonObj::IsGlobalHasServerOpened() {
	std::lock_guard<std::mutex> lk(has_opened_mutex);
	return global_has_server_opened_;
}
void SingletonObj::SetGlobalHasServerOpened(bool global_has_server_opened) {
	std::lock_guard<std::mutex> lk(has_opened_mutex);
	global_has_server_opened_ = global_has_server_opened;
}
SymbolTable *SingletonObj::GetSymbolTable() {
	return symbol_table_;
}
//void SingletonObj::SetSymbolTable(SymbolTable *symbol_table) {
//	symbol_table_ = symbol_table;
//}
ServerSymbolTable *SingletonObj::GetServerSymbolTable() {
	return server_symbol_table_;
}
//void SingletonObj::SetServerSymbolTable(ServerSymbolTable *server_symbol_table) {
//	server_symbol_table_ = server_symbol_table;
//}
std::queue<std::pair<std::string, double>> *SingletonObj::GetMessagesQueue() {
	return messages_queue_;
}
void SingletonObj::SetMessagesQueue(std::queue<std::pair<std::string, double>> *messages_queue) {
	messages_queue_ = messages_queue;
}
bool SingletonObj::IsShouldStopClientThread() {
	std::lock_guard<std::mutex> lk(client_mutex);
	return should_stop_client_thread_;
}
void SingletonObj::SetShouldStopClientThread(bool should_stop_client_thread) {
	std::lock_guard<std::mutex> lk(client_mutex);
	should_stop_client_thread_ = should_stop_client_thread;
}
bool SingletonObj::IsShouldStopServerThread() {
	std::lock_guard<std::mutex> lk(thread_mutex);
	return should_stop_server_thread_;
}
void SingletonObj::SetShouldStopServerThread(bool should_stop_server_thread) {
	std::lock_guard<std::mutex> lk(thread_mutex);
	should_stop_server_thread_ = should_stop_server_thread;
}
bool SingletonObj::IsHaveConnectedAsClient() {
	std::lock_guard<std::mutex> lk(connected_as_client_mutex);
	return have_connected_as_client_;
}
void SingletonObj::SetHaveConnectedAsClient(bool have_connected_as_client) {
	std::lock_guard<std::mutex> lk(connected_as_client_mutex);
	have_connected_as_client_ = have_connected_as_client;
}
//bool SingletonObj::IsShouldStopClientThread() {
//	std::lock_guard<std::mutex> lk(client_mutex);
//	return should_stop_client_thread;
//}
//void SingletonObj::SetShouldStopClientThread(bool should_stop_client_thread) {
//	std::lock_guard<std::mutex> lk(client_mutex);
//	SingletonObj::should_stop_client_thread = should_stop_client_thread;
//}
//bool SingletonObj::IsShouldStopServerThread() {
//	std::lock_guard<std::mutex> lk(thread_mutex);
//	return should_stop_server_thread;
//}
//void SingletonObj::SetShouldStopServerThread(bool should_stop_server_thread) {
//	std::lock_guard<std::mutex> lk(thread_mutex);
//	SingletonObj::should_stop_server_thread = should_stop_server_thread;
//}
//bool SingletonObj::IsHaveConnectedAsClient() {
//	std::lock_guard<std::mutex> lk(connected_as_client_mutex);
//	return have_connected_as_client;
//}
//void SingletonObj::SetHaveConnectedAsClient(bool have_connected_as_client) {
//	std::lock_guard<std::mutex> lk(connected_as_client_mutex);
//	SingletonObj::have_connected_as_client = have_connected_as_client;
//}
