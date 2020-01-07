//
// Created by חן גולדשטיין on 04/01/2020.
//

#ifndef ADVANCED1_HW3__COMMAND_H_
#define ADVANCED1_HW3__COMMAND_H_
#include <string>
#include <iostream>
//#include <thread>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
/**
 * Command Interface
 */

class Command {
 public:
	virtual int execute(std::string var) = 0;
	virtual ~Command() {}

};

#endif //ADVANCED1_HW3__COMMAND_H_
