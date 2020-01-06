//
// Created by חן גולדשטיין on 04/01/2020.
//

#include "ConnectClientCommand.h"

ConnectClientCommand::ConnectClientCommand(const char *ipAddress, int port) {
	this->ipAddress = ipAddress;
	this->port = port;
}

ConnectClientCommand::~ConnectClientCommand() = default;

int ConnectClientCommand::execute(std::string var) {
	//TODO: CHECK IF THE SOCKET OPENING IS A BLOCKING FUNCTION - NEEDS TO OPEN A THREAD TO IT OTHERWISE IT WILL STUCK
	//TODO: THE WHOLE PROGRAM
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cerr << "\n Socket creation error \n" << std::endl;
		return -1;
	}

	this->serv_addr->sin_family = AF_INET;
	this->serv_addr->sin_addr.s_addr = inet_addr(ipAddress);
	this->serv_addr->sin_port = htons(this->port);


//	TODO: CREATE THE THREAD AND START SENDING STUFF ( OFR SOMEHOW, TALK TO MILO)
	std::thread connectClient(&ConnectClientCommand::connectToServer);
	return 1;
}

int ConnectClientCommand::connectToServer() {

	//אני צריך לעשות שעד שאני פותח שרת שמקבל את הסימולטור כלקוח אני לא פותח את הלקוח שלי?
	// אז אני יכול לעשות משתנה גלובאלי
	//TODO: DONT CONNECT UNTIL YOU CREATED A SERVER.
	while (!global_has_server_opened) {
		// do nothing - just wait for us to connect to the simulator as a server (the sim is the client) and then
		// connect as a client
	}
	int is_connect = connect(this->sockfd, (struct sockaddr *) &(this->serv_addr), sizeof(this->serv_addr));
	if (is_connect < 0) {
		std::cerr << "\ncould not connect to host server\n" << std::endl;
		return -2;
	}
	return 1;
}

//TODO: NEED TO HAVE A "SEND" FUNCTION - IN THE MAIN PROBABLY, TO SEND THE MESSAGES WITH THE CLIENT.