//
// Created by yoavst22 on 06/01/2020.
//

#ifndef ADVANCED1_HW3__LEXER_H_
#define ADVANCED1_HW3__LEXER_H_
using namespace std;
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <fstream>
class Lexer {
 public:
  virtual ~Lexer() {};
  //this function delete the spaces in the string, unless the space is in " "
  string delete_spaces(string str);
  list<string> *lexer(string file_name);
};
#endif //ADVANCED1_HW3__LEXER_H_
