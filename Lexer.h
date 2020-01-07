//
// Created by yoavst22 on 06/01/2020.
//

#ifndef ADVANCED1_HW3__LEXER_H_
#define ADVANCED1_HW3__LEXER_H_
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <fstream>
class Lexer {
 public:
  virtual ~Lexer() {};
  //this function delete the spaces in the string, unless the space is in " "
  std::string delete_spaces(std::string str);
  std::list<std::string> *lexer(std::string file_name);
};
#endif //ADVANCED1_HW3__LEXER_H_
