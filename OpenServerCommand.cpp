//
// Created by חן גולדשטיין on 04/01/2020.
//

#include "OpenServerCommand.h"

OpenServerCommand::OpenServerCommand(int port) {
	this->port = port;
}

OpenServerCommand::~OpenServerCommand() = default;

int OpenServerCommand::execute(std::string var) {
	//TODO: CHECK IF THE SOCKET OPENING IS A BLOCKING FUNCTION - NEEDS TO OPEN A THREAD TO IT OTHERWISE IT WILL STUCK
	//TODO: THE WHOLE PROGRAM
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cerr << "\n Socket creation error \n" << std::endl;
		return -1;
	}

	this->serv_addr->sin_family = AF_INET;
	this->serv_addr->sin_addr.s_addr = INADDR_ANY;
	this->serv_addr->sin_port = htons(this->port);


//	TODO: CREATE THE THREAD AND START RECEIVING STUFF ( OFR SOMEHOW, TALK TO MILO)
	std::thread openServer(&OpenServerCommand::acceptClient);
	return 1;
}

int OpenServerCommand::acceptClient() {
	int bind_flag = bind(this->sockfd, (struct sockaddr *) &(this->serv_addr), sizeof(this->serv_addr));
	int new_socket;
	if (bind_flag < 0) {
		std::cerr << "bind failed" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (listen(this->sockfd, 1) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(this->sockfd, (struct sockaddr *) &this->serv_addr,
							 (socklen_t *) &this->serv_addr)) < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}
	global_has_server_opened = true;

	// TODO: NEED TO HAVE THE ACCEPT MESSAGE FUNCTION. THE FUNCTION THAT READS THE VALUES. THE FUNC THAT UPDATES THE
	//TODO: SYMBOL TABLE OF THE (PATH, VARS) (AND THEN THE VALUES OF THE VARS).

	/**
	 * WE MIGHT RETURN THE NEW_SOCKET AND THEN READ FROM ITS ADDRESS.
	 */
	return 1;
}
