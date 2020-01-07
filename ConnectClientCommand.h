//
// Created by חן גולדשטיין on 04/01/2020.
//

#ifndef ADVANCED1_HW3__CONNECTCLIENTCOMMAND_H_
#define ADVANCED1_HW3__CONNECTCLIENTCOMMAND_H_

#include "Command.h"
#include <thread>
#include <arpa/inet.h>
#include "SingletonObj.h"

class ConnectClientCommand : public Command {
 protected:
	struct sockaddr_in *serv_addr;
	const char *ipAddress;
	int port;
	int sockfd;

 public:
	ConnectClientCommand(const char *ipAddress, int port);

	virtual ~ConnectClientCommand();

//	int connectToServer();
	sockaddr_in *GetServAddr() const;
	void SetServAddr(sockaddr_in *serv_addr);
	const char *GetIpAddress() const;
	void SetIpAddress(const char *ip_address);
	int GetPort() const;
	void SetPort(int port);
	int GetSockfd() const;
	void SetSockfd(int sockfd);
	int execute(std::string var) override; // SENDING THE MESSAGE

	int updateVarInSimulator(std::string varName, int newVarValue, SymbolTable *sm);

};

#endif //ADVANCED1_HW3__CONNECTCLIENTCOMMAND_H_
