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
	struct sockaddr_in serv_addr;
	char *ipAddress;
	int port;
	int sockfd;

 public:
	ConnectClientCommand(const char *ipAddress, std::string exp, int n);

	virtual ~ConnectClientCommand();

//	int connectToServer();
	sockaddr_in *GetServAddr();
//	void SetServAddr(sockaddr_in serv_addr);
	const char *GetIpAddress();
	//void SetIpAddress(const char *ip_address);
	int GetPort();
	void SetPort(int port);
	int GetSockfd();
//	void SetSockfd(int sockfd);
	int execute(std::string var) override; // SENDING THE MESSAGE

	int updateVarInSimulator();

};

#endif //ADVANCED1_HW3__CONNECTCLIENTCOMMAND_H_
