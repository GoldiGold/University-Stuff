//
// Created by yoavst22 on 18/12/2019.
//
using namespace std;
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <fstream>
class Lexer {
 public:
  string delete_spaces(string str) {
    if (str[0] == '"' && str[str.length() - 1] == '"') {
      return str;
    }
    while (str.find_first_of(" ") != -1) { //delete the spaces
      str.erase(str.begin() + str.find_first_of(" "));
    }
    return str;
  }

  list<string>* lexer(string file_name) {
    auto lst = new list<string>();

    ifstream infile(file_name);
    string line;
    while (getline(infile, line)) { //for line in file
      string str = line;

      while (str.length() > 0) { //split the line
        if (str[0] == '=') {
          lst->push_back("=");
          str = str.substr(1, str.length());
          str = delete_spaces(str);
          lst->push_back(str);
          str = "";
          continue;
        } else if (str.find("openDataServer(") == 0) {
          lst->push_back("openDataServer");
          str = str.substr(15, (str.length()-16));
          str = delete_spaces(str);
          lst->push_back(str);
          str = "";
          continue;
        } else if (str.find("connectControlClient(") == 0) {
          lst->push_back("connectControlClient");
          str = str.substr(21, (str.length()-22));
          lst->push_back(delete_spaces(str.substr(0, str.find(","))));
          lst->push_back(delete_spaces(str.substr(str.find(",") + 1, str.length())));
          str = "";
          continue;
        } else if (str.find("sim(") == 0) {
          lst->push_back("sim");
          str = str.substr(4, (str.length()-5));
          lst->push_back(delete_spaces(str));
          str = "";
          continue;
        } else if (str.find("Print(") == 0) {
          lst->push_back("Print");
          str = str.substr(6, (str.length()-7));
          lst->push_back(delete_spaces(str));
          str = "";
          continue;
        }

        int space = str.find_first_of(" ");
        if (space == -1) {
          space = str.length();
        }

        if (space == str.length()){
          lst->push_back(str);
          str = "";
        } else {
          lst->push_back(str.substr(0, space));
          str = str.substr(space + 1, str.length());
        }
      }
      lst->push_back(";");
    }

    return lst;
  }
};
