//
// Created by חן גולדשטיין on 04/01/2020.
//

#include "ConnectClientCommand.h"

ConnectClientCommand::ConnectClientCommand(const char *ipAddress, std::string exp) {
	this->ipAddress = ipAddress;
	this->port = SingletonObj::getInstance()->GetInter()->interpret(exp)->calculate();

}

ConnectClientCommand::~ConnectClientCommand() = default;

int connectToServer(ConnectClientCommand *connect_client_command) {
	//אני צריך לעשות שעד שאני פותח שרת שמקבל את הסימולטור כלקוח אני לא פותח את הלקוח שלי?
	// אז אני יכול לעשות משתנה גלובאלי
	//TODO: DONT CONNECT UNTIL YOU CREATED A SERVER.
	while (!SingletonObj::getInstance()->IsGlobalHasServerOpened()) {
		// do nothing - just wait for us to connect to the simulator as a server (the sim is the client) and then
		// connect as a client
	}
	int is_connect = connect(connect_client_command->GetSockfd(),
							 (struct sockaddr *) (connect_client_command->GetServAddr()),
							 sizeof(*(connect_client_command->GetServAddr())));
	if (is_connect < 0) {
		std::cerr << "\ncould not connect to host server\n" << std::endl;
		return -2;
	}

	while (!SingletonObj::getInstance()->IsShouldStopClientThread()) {
		connect_client_command->updateVarInSimulator();
		// WAITING SO WE WILL NOT ENTER SO MANY FUNCTIONS ALL THE TIME.
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	/**
	 * WE MIGHT RETURN THE NEW_SOCKET AND THEN READ FROM ITS ADDRESS.
	 */
	return connect_client_command->GetSockfd(); // so we will know where to send messages NOT REALLY NEEDED SINCE THE SEND/WRITE FUNCTION IS OF THE CLASS.
}

int ConnectClientCommand::updateVarInSimulator(/*std::string varName, int newVarValue, SymbolTable *sm*/) {
	// If there is a message waiting in the update queue
	std::string message;
	ssize_t return_val;
	SingletonObj *single = SingletonObj::getInstance();
	if (!single->GetMessagesQueue()->empty()) {
		message = "set " + single->GetSymbolTable()->getSim(single->GetMessagesQueue()->front().first) + " "
			+ std::to_string(single->GetMessagesQueue()->front().second) + "\r\n";
		single->GetMessagesQueue()->pop();
		return_val = write(this->sockfd, message.c_str(), message.length());
		std::cout << "the message:" << message << std::endl;
		return return_val; // A message was sent.
	}
	return -1; // No message was sent
}

int ConnectClientCommand::execute(std::string var) {
	//TODO: CHECK IF THE SOCKET OPENING IS A BLOCKING FUNCTION - NEEDS TO OPEN A THREAD TO IT OTHERWISE IT WILL STUCK
	//TODO: THE WHOLE PROGRAM
	this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cerr << "\n Socket creation error \n" << std::endl;
		return -1;
	}

	this->serv_addr.sin_family = AF_INET;
	this->serv_addr.sin_addr.s_addr = inet_addr(ipAddress);
	this->serv_addr.sin_port = htons(this->port);


//	TODO: CREATE THE THREAD AND START SENDING STUFF ( OFR SOMEHOW, TALK TO MILO)
	std::thread connectClient(connectToServer, this);
	connectClient.detach();
	return 2; // THE AMOUNT OF SKIPS NEEDED TO BE DONE IN THE PARSER ARRAY
}

sockaddr_in *ConnectClientCommand::GetServAddr() {
	return &serv_addr;
}
void ConnectClientCommand::SetServAddr(sockaddr_in serv_addr) {
	ConnectClientCommand::serv_addr = serv_addr;
}
const char *ConnectClientCommand::GetIpAddress() {
	return ipAddress;
}
void ConnectClientCommand::SetIpAddress(const char *ip_address) {
	ipAddress = ip_address;
}
int ConnectClientCommand::GetPort() {
	return port;
}
void ConnectClientCommand::SetPort(int port) {
	ConnectClientCommand::port = port;
}
int ConnectClientCommand::GetSockfd() {
	return sockfd;
}
void ConnectClientCommand::SetSockfd(int sockfd) {
	ConnectClientCommand::sockfd = sockfd;
}
//TODO: NEED TO HAVE A "SEND" FUNCTION - IN THE MAIN PROBABLY, TO SEND THE MESSAGES WITH THE CLIENT.