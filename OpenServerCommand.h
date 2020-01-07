//
// Created by חן גולדשטיין on 04/01/2020.
//

#ifndef ADVANCED1_HW3__OPENSERVERCOMMAND_H_
#define ADVANCED1_HW3__OPENSERVERCOMMAND_H_

#include "Command.h"
#include <thread>
#include "SingletonObj.h"

class OpenServerCommand : public Command {
 protected:
	struct sockaddr_in *serv_addr;
	int port;
	int sockfd;

 public:
	explicit OpenServerCommand(int port);

	virtual ~OpenServerCommand();

	sockaddr_in *GetServAddr() const;
	void SetServAddr(sockaddr_in *serv_addr);
	int GetPort() const;
	void SetPort(int port);
	int GetSockfd() const;
	void SetSockfd(int sockfd);
//	int acceptClient();

	int execute(std::string var) override; // SENDING THE MESSAGE


};

#endif //ADVANCED1_HW3__OPENSERVERCOMMAND_H_
