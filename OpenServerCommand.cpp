//
// Created by חן גולדשטיין on 04/01/2020.
//

#include "OpenServerCommand.h"

OpenServerCommand::OpenServerCommand(std::string exp) {
	this->port = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();
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

	// TODO: NEED TO HAVE THE ACCEPT MESSAGE FUNCTION. THE FUNCTION THAT READS THE VALUES. THE FUNC THAT UPDATES THE
	//TODO: SYMBOL TABLE OF THE (PATH, VARS) (AND THEN THE VALUES OF THE VARS).
	// TODO: NEED TO HAVE THE ACCEPT MESSAGE FUNCTION. THE FUNCTION THAT READS THE VALUES. THE FUNC THAT UPDATES THE
	//TODO: SYMBOL TABLE OF THE (PATH, VARS) (AND THEN THE VALUES OF THE VARS).
	// TODO: NEED TO HAVE THE ACCEPT MESSAGE FUNCTION. THE FUNCTION THAT READS THE VALUES. THE FUNC THAT UPDATES THE
	//TODO: SYMBOL TABLE OF THE (PATH, VARS) (AND THEN THE VALUES OF THE VARS).

	/**
	 * WE MIGHT RETURN THE NEW_SOCKET AND THEN READ FROM ITS ADDRESS.
	 */

	std::cout << "we have a connection to the client" << std::endl;
	char buffer[1024];
	while (!SingletonObj::getInstance()->IsShouldStopServerThread()) {
		ssize_t size = read(new_socket, buffer, 1024);
		std::string t = buffer;
		std::vector<std::string> values = split(t, ',');
		int counter = 0;
		for (auto const &iterator : *SingletonObj::getInstance()->GetServerSymbolTable()->GetM()) {
			SingletonObj::getInstance()->GetServerSymbolTable()->updateAtSymbolTable(iterator.first,
																					 stod(values[counter]),
																					 SingletonObj::getInstance()->GetSymbolTable());
			++counter;
			std::cout << "A message has been received" << std::endl;
		}
	}
	return new_socket; //so we will have the new socket we listen to.
}

int OpenServerCommand::execute(std::string var) {
	//TODO: CHECK IF THE SOCKET OPENING IS A BLOCKING FUNCTION - NEEDS TO OPEN A THREAD TO IT OTHERWISE IT WILL STUCK
	//TODO: THE WHOLE PROGRAM
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cerr << "\n Socket creation error \n" << std::endl;
		return -1;
	}

	this->serv_addr.sin_family = AF_INET;
	this->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	this->serv_addr.sin_port = htons(this->port);

	std::cout << "we have a Created the socket of the server" << std::endl;

//	TODO: CREATE THE THREAD AND START RECEIVING STUFF ( OR SOMEHOW, TALK TO MILO)
	std::thread openServer(acceptClient, this);
	openServer.detach();
	return 2; // THE AMOUNT OF SKIPS NEEDED TO BE DONE IN THE PARSER ARRAY
}

sockaddr_in *OpenServerCommand::GetServAddr() {
	return &serv_addr;
}
void OpenServerCommand::SetServAddr(sockaddr_in serv_addr) {
	OpenServerCommand::serv_addr = serv_addr;
}
int OpenServerCommand::GetPort() {
	return port;
}
void OpenServerCommand::SetPort(int port) {
	OpenServerCommand::port = port;
}
int OpenServerCommand::GetSockfd() {
	return sockfd;
}
void OpenServerCommand::SetSockfd(int sockfd) {
	OpenServerCommand::sockfd = sockfd;
}
