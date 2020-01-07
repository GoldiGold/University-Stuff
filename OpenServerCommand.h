//
// Created by חן גולדשטיין on 04/01/2020.
//

#ifndef ADVANCED1_HW3__OPENSERVERCOMMAND_H_
#define ADVANCED1_HW3__OPENSERVERCOMMAND_H_

#include "Command.h"


class OpenServerCommand : public Command {
 protected:
	struct sockaddr_in *serv_addr;
	int port;
	int sockfd;

 public:
	explicit OpenServerCommand(int port);

	virtual ~OpenServerCommand();

	int acceptClient();

	int execute(std::string var) override; // SENDING THE MESSAGE


};

#endif //ADVANCED1_HW3__OPENSERVERCOMMAND_H_
