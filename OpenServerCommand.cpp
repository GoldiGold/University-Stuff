//
// Created by חן גולדשטיין on 04/01/2020.
//

#include "OpenServerCommand.h"
#define BUFFER_SIZE 1024
#define VALUES_SIZE 36

OpenServerCommand::OpenServerCommand(std::string exp) {
	SingletonObj::getInstance()->interpreter_mutex.lock();
	this->port = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();
	SingletonObj::getInstance()->interpreter_mutex.unlock();
}

OpenServerCommand::~OpenServerCommand() = default;

std::vector<std::string> split(const std::string &s, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

int acceptClient(OpenServerCommand *open_server_command) {
	int bind_flag = bind(open_server_command->GetSockfd(),
						 (struct sockaddr *) (open_server_command->GetServAddr()),
						 sizeof(*(open_server_command->GetServAddr())));
	int new_socket;
	if (bind_flag < 0) {
		std::cerr << "bind failed" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (listen(open_server_command->GetSockfd(), 1) < 0) {
		std::cerr << "listen error" << std::endl;
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(open_server_command->GetSockfd(), (struct sockaddr *) open_server_command->GetServAddr(),
							 (socklen_t *) open_server_command->GetServAddr())) < 0) {
		std::cerr << "accept error" << std::endl;
		exit(EXIT_FAILURE);
	}
	SingletonObj::getInstance()->SetGlobalHasServerOpened(true);

	/**
	 * WE MIGHT RETURN THE NEW_SOCKET AND THEN READ FROM ITS ADDRESS. 0.5,0.1
	 * 4565\n1,2,3,4,5
	 */

//	std::cout << "we have a connection to the client" << std::endl;
	char buffer[BUFFER_SIZE];
	bool need_complete = false; // indicates if the previous buffer needed completion.
	std::vector<std::string> sub_n;
	std::vector<std::string> temp_sub_n;
	std::vector<std::string> values;
	std::vector<std::string> temp_values;
	char last;

	while (!SingletonObj::getInstance()->IsShouldStopServerThread()) {
		ssize_t size = read(new_socket, buffer, BUFFER_SIZE);
		std::string t = buffer;

//		std::cout << "the buffer has: " << t << std::endl;

		if (size < 1024) { // the buffer hasn't filled up:
//			std::cout << "the buffer has lass than 1024" << std::endl;
			if (need_complete) {
//				std::cout << "there is a need to complete" << std::endl;

				temp_sub_n = split(t, '\n');
				// appending the reminder from the new buffer to the string of 36 values
				sub_n[sub_n.size() - 1].append(temp_sub_n[0]);
				//saving only the first values from the new buffer that and the last values from the last buffer (together 36)
				temp_values = split(sub_n[sub_n.size() - 1], ',');
				int counter = 0;
				SingletonObj::getInstance()->symbol_table_mutex.lock();
				SingletonObj::getInstance()->server_symbol_table_mutex.lock();
				if (!temp_values.empty()) {
					for (auto const
							&iterator : *SingletonObj::getInstance()->GetServerSymbolTable()->GetInsertionOrder()) {
						try {
							SingletonObj::getInstance()->GetServerSymbolTable()->updateAtSymbolTable(iterator,
																									 stod(temp_values[counter]),
																									 SingletonObj::getInstance()->GetSymbolTable());
						} catch (...){
							std::cout << "the string is:" << temp_values[counter];
						}
						++counter;
//						std::cout << "A message has been recieved" << std::endl;
					}
				}
				SingletonObj::getInstance()->server_symbol_table_mutex.unlock();
				SingletonObj::getInstance()->symbol_table_mutex.unlock();
				for (int kI = 1; kI < signed(temp_sub_n.size()); ++kI) {
					values = split(temp_sub_n[kI], ',');
					counter = 0;
					SingletonObj::getInstance()->symbol_table_mutex.lock();
					SingletonObj::getInstance()->server_symbol_table_mutex.lock();
					if (!values.empty()) {
						for (auto const
								&iterator : *SingletonObj::getInstance()->GetServerSymbolTable()->GetInsertionOrder()) {
							try{
							SingletonObj::getInstance()->GetServerSymbolTable()->updateAtSymbolTable(iterator,
																									 stod(values[counter]),
																									 SingletonObj::getInstance()->GetSymbolTable());
							} catch (...){
								std::cout << "the string is:" << values[counter];
							}
							++counter;
//						std::cout << "A message has been recieved" << std::endl;
						}
					}
					SingletonObj::getInstance()->server_symbol_table_mutex.unlock();
					SingletonObj::getInstance()->symbol_table_mutex.unlock();
				}

				need_complete = false; // because the buffer isn't full.
			} else {
//				std::cout << "there is no need to complete" << std::endl;
				sub_n = split(t, '\n');
//				std::cout << "created sub_n" << std::endl;
				for (int kI = 0; kI < signed(sub_n.size()); ++kI) {
					values = split(sub_n[kI], ',');
//					std::cout << "created the values" << std::endl;
					int counter = 0;
					SingletonObj::getInstance()->symbol_table_mutex.lock();
					SingletonObj::getInstance()->server_symbol_table_mutex.lock();

//					std::cout << "locked the tables" << std::endl;
					if (!values.empty()) {
						for (auto const
								&iterator : *SingletonObj::getInstance()->GetServerSymbolTable()->GetInsertionOrder()) {
							try{
							SingletonObj::getInstance()->GetServerSymbolTable()->updateAtSymbolTable(iterator,
																									 stod(values[counter]),
																									 SingletonObj::getInstance()->GetSymbolTable());
							} catch (...){
								std::cout << "the string is:" << values[counter];
							}
							++counter;
//						std::cout << "A message has been recieved" << std::endl;
						}
					}
					SingletonObj::getInstance()->server_symbol_table_mutex.unlock();
					SingletonObj::getInstance()->symbol_table_mutex.unlock();
				}
				need_complete = false;
			}

		} else { // size == 1024
//			std::cout << "the buffer has 1024" << std::endl;
			last = buffer[BUFFER_SIZE - 1];
			if (need_complete) {
//				std::cout << "there is a need to complete" << std::endl;
				temp_sub_n = split(t, '\n');
				// appending the reminder from the new buffer to the string of 36 values
				sub_n[sub_n.size() - 1].append(temp_sub_n[0]);
				//saving only the first values from the new buffer that and the last values from the last buffer (together 36)
				temp_values = split(sub_n[sub_n.size() - 1], ',');
				int counter = 0;
				SingletonObj::getInstance()->symbol_table_mutex.lock();
				SingletonObj::getInstance()->server_symbol_table_mutex.lock();

//				if(temp_values != null) {
				if (!temp_values.empty()) {
					for (auto const
							&iterator : *SingletonObj::getInstance()->GetServerSymbolTable()->GetInsertionOrder()) {
						try{
						SingletonObj::getInstance()->GetServerSymbolTable()->updateAtSymbolTable(iterator,
																								 stod(temp_values[counter]),
																								 SingletonObj::getInstance()->GetSymbolTable());
						} catch (...){
							std::cout << "the string is:" << temp_values[counter];
						}
						++counter;
//						std::cout << "A message has been recieved" << std::endl;
					}
				}
				SingletonObj::getInstance()->server_symbol_table_mutex.unlock();
				SingletonObj::getInstance()->symbol_table_mutex.unlock();
				for (int kI = 1; kI < signed(temp_sub_n.size() - 1); ++kI) {
					values = split(temp_sub_n[kI], ',');
					counter = 0;
					SingletonObj::getInstance()->symbol_table_mutex.lock();
					SingletonObj::getInstance()->server_symbol_table_mutex.lock();
					if (!values.empty()) {
						for (auto const
								&iterator : *SingletonObj::getInstance()->GetServerSymbolTable()->GetInsertionOrder()) {
							try{
							SingletonObj::getInstance()->GetServerSymbolTable()->updateAtSymbolTable(iterator,
																									 stod(values[counter]),
																									 SingletonObj::getInstance()->GetSymbolTable());
							} catch (...){
								std::cout << "the string is:" << values[counter];
							}
							++counter;
//						std::cout << "A message has been recieved" << std::endl;
						}
					}
					SingletonObj::getInstance()->server_symbol_table_mutex.unlock();
					SingletonObj::getInstance()->symbol_table_mutex.unlock();
				}

				if (last == '\n') {
					need_complete = true;
					sub_n.clear();
					sub_n = temp_sub_n; // assigning the values of temp to sub_n.
				} else {
					//doing the last interation.
					values = split(temp_sub_n[temp_sub_n.size() - 1], ',');
					counter = 0;
					SingletonObj::getInstance()->symbol_table_mutex.lock();
					SingletonObj::getInstance()->server_symbol_table_mutex.lock();
					if (!values.empty()) {
						for (auto const
								&iterator : *SingletonObj::getInstance()->GetServerSymbolTable()->GetInsertionOrder()) {
							try{
							SingletonObj::getInstance()->GetServerSymbolTable()->updateAtSymbolTable(iterator,
																									 stod(values[counter]),
																									 SingletonObj::getInstance()->GetSymbolTable());
							} catch (...){
								std::cout << "the string is:" << values[counter];
							}
							++counter;
//						std::cout << "A message has been recieved" << std::endl;
						}
					}
					SingletonObj::getInstance()->server_symbol_table_mutex.unlock();
					SingletonObj::getInstance()->symbol_table_mutex.unlock();
					need_complete = false;

				}
			} else {
//				std::cout << "there is no need to complete" << std::endl;
				sub_n = split(t, '\n');
				for (int kI = 0; kI < signed(sub_n.size() - 1); ++kI) {
					values = split(sub_n[kI], ',');
					int counter = 0;
					SingletonObj::getInstance()->symbol_table_mutex.lock();
					SingletonObj::getInstance()->server_symbol_table_mutex.lock();
					if (!values.empty()) {
						for (auto const
								&iterator : *SingletonObj::getInstance()->GetServerSymbolTable()->GetInsertionOrder()) {
							try{
							SingletonObj::getInstance()->GetServerSymbolTable()->updateAtSymbolTable(iterator,
																									 stod(values[counter]),
																									 SingletonObj::getInstance()->GetSymbolTable());
							} catch (...){
								std::cout << "the string is:" << values[counter];
							}
							++counter;
//						std::cout << "A message has been recieved" << std::endl;
						}
					}
					SingletonObj::getInstance()->server_symbol_table_mutex.unlock();
					SingletonObj::getInstance()->symbol_table_mutex.unlock();
				}
				if (last == '\n') {
					need_complete = true;
//					sub_n.clear();
//					sub_n = temp_sub_n; // assigning the values of temp to sub_n.
				} else {
					//doing the last interation.
					values = split(sub_n[sub_n.size() - 1], ',');
					int counter = 0;
					SingletonObj::getInstance()->symbol_table_mutex.lock();
					SingletonObj::getInstance()->server_symbol_table_mutex.lock();

					if (!values.empty()) {
						for (auto const
								&iterator : *SingletonObj::getInstance()->GetServerSymbolTable()->GetInsertionOrder()) {
							try{
								SingletonObj::getInstance()->GetServerSymbolTable()->updateAtSymbolTable(iterator,
																									 stod(values[counter]),
																									 SingletonObj::getInstance()->GetSymbolTable());
						} catch (...){
							std::cout << "the string is:" << values[counter];
						}
							++counter;
//						std::cout << "A message has been recieved" << std::endl;
						}
					}
					SingletonObj::getInstance()->server_symbol_table_mutex.unlock();
					SingletonObj::getInstance()->symbol_table_mutex.unlock();
					need_complete = false;
				}
			}
		}
//		need_complete = true; // remember to delete.
	}
//		std::string t = buffer;
//		std::vector<std::string> sub_n = split(t, '\n');
//		std::vector<std::string> values;
//		    for (int kI = 0; kI < sub_n.size(); ++kI) {
//				 values = split(sub_n[kI], ',');
//				int counter = 0;
//				SingletonObj::getInstance()->symbol_table_mutex.lock();
//				SingletonObj::getInstance()->server_symbol_table_mutex.lock();
//
//				for (auto const &iterator : *SingletonObj::getInstance()->GetServerSymbolTable()->GetM()) {
//
//					SingletonObj::getInstance()->GetServerSymbolTable()->updateAtSymbolTable(iterator.first,
//																							 stod(values[counter]),
//																							 SingletonObj::getInstance()->GetSymbolTable());
//					++counter;
//					std::cout << "A message has been recieved" << std::endl;
//				}
//				SingletonObj::getInstance()->server_symbol_table_mutex.unlock();
//				SingletonObj::getInstance()->symbol_table_mutex.unlock();
//			}
//
//		}


	close(new_socket);
	close(open_server_command->GetSockfd());
	return 1; //so we will have the new socket we listen to.
}

void OpenServerCommand::execute() {
	//TODO: CHECK IF THE SOCKET OPENING IS A BLOCKING FUNCTION - NEEDS TO OPEN A THREAD TO IT OTHERWISE IT WILL STUCK
	//TODO: THE WHOLE PROGRAM
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cerr << "\n Socket creation error \n" << std::endl;
	}

	this->serv_addr.sin_family = AF_INET;
	this->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	this->serv_addr.sin_port = htons(this->port);

//	std::cout << "we have a Created the socket of the server" << std::endl;

//	TODO: CREATE THE THREAD AND START RECEIVING STUFF ( OR SOMEHOW, TALK TO MILO)
	std::thread openServer(acceptClient, this);
	openServer.detach();
}

sockaddr_in *OpenServerCommand::GetServAddr() {
	return &serv_addr;
}
void OpenServerCommand::SetServAddr(sockaddr_in serv_addr1) {
	OpenServerCommand::serv_addr = serv_addr1;
}
int OpenServerCommand::GetPort() {
	return port;
}
void OpenServerCommand::SetPort(int port1) {
	OpenServerCommand::port = port1;
}
int OpenServerCommand::GetSockfd() {
	return sockfd;
}
void OpenServerCommand::SetSockfd(int sockfd1) {
	OpenServerCommand::sockfd = sockfd1;
}
