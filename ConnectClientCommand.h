//
// Created by חן גולדשטיין on 04/01/2020.
//

#ifndef ADVANCED1_HW3__CONNECTCLIENTCOMMAND_H_
#define ADVANCED1_HW3__CONNECTCLIENTCOMMAND_H_

#include "Command.h"
#include <arpa/inet.h>
#include "SymbolTable.h"

class ConnectClientCommand : public Command {
 protected:
	struct sockaddr_in *serv_addr;
	const char *ipAddress;
	int port;
	int sockfd;

 public:
	ConnectClientCommand(const char *ipAddress, int port);

	virtual ~ConnectClientCommand();

	int connectToServer();

	int execute(std::string var) override; // SENDING THE MESSAGE

	int updateVarInSimulator(std::string varName, int newVarValue, SymbolTable *sm);

};

#endif //ADVANCED1_HW3__CONNECTCLIENTCOMMAND_H_
