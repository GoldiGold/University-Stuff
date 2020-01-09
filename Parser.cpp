//
// Created by yoavst22 on 09/01/2020.
//

#include "Parser.h"
Parser::Parser(std::list<std::string>* l){
  using namespace std;
  strList = l;
  commands = new list<Command*>();
  it = strList->begin();
  while(it != strList->end()) {
    commands->push_back(createCom());
    it++;
  }
}

Command* Parser::createCom(){
  using namespace std;
  if(!(*it).compare("Print")){
    it++;
    auto c = new PrintCommand(*it);
    return c;
  } else if(!(*it).compare("Sleep")){
    it++;
    auto c = new SleepCommand(*it);
    return c;
  } else if(!(*it).compare("openDataServer")){
    it++;
    auto c = new OpenServerCommand(*it);
    return c;
  } else if(!(*it).compare("connectControlClient")){
    string ip = *(++it);
    string port = *(++it);
    auto c = new ConnectClientCommand(ip.c_str(), port);
    return c;
  } else if(!(*it).compare("var")){
    string var = *(++it);
    it++;
    if(!(*it).compare("->")) {
      it++;
      string sim = *(++it);
      auto c = new DefineVarRightCommand(var, sim.substr(1, sim.length()-2));
      return c;
    } else if(!(*it).compare("<-")){
      it++;
      string sim = *(++it);
      auto c = new DefineVarLeftCommand(var, sim.substr(1, sim.length()-2));
      return c;
    } else if(!(*it).compare("=")){
      string exp = *(++it);
      auto c = new DefineVarEqCommand(var, exp);
      return c;
    } else {
      throw "invalid define var command";
    }
  } else if(!(*it).compare("if")){
    string exp1 = *(++it);
    string oper = *(++it);
    string exp2 = *(++it);
    auto c = new IfCommand(exp1, oper, exp2);
    it++;
    if(!(*it).compare("{")) {
      it++;
      while((*it).compare("}")) {
        Command* ic = createCom();//inner command
        c->addCommand(ic);
        it++;
      }
      return c;
    } else {
      throw "invalid if command";
    }
  } else if(!(*it).compare("while")){
    string exp1 = *(++it);
    string oper = *(++it);
    string exp2 = *(++it);
    auto c = new WhileCommand(exp1, oper, exp2);
    it++;
    if(!(*it).compare("{")) {
      it++;
      while((*it).compare("}")) {
        Command* ic = createCom();//inner command
        c->addCommand(ic);
        it++;
      }
      return c;
    } else {
      throw "invalid while command";
    }
  } else {
    string var = *it;
    it++;
    if(!(*it).compare("=")) {
      string exp = *(++it);
      auto c = new PutCommand(var, exp);
      return c;
    } else {
      throw "invalid command";
    }
  }
}

void Parser::execute(){
  for(Command* com: *commands){
    com->execute("");
  }
}