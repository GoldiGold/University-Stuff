//
// Created by yoavst22 on 18/12/2019.
//
#include "Lexer.h"
//this function delete the spaces in the string, unless the space is in " "
std::string Lexer::delete_spaces(std::string str) {
	int isQuote = 0; //are we inside a ""
	for (unsigned int i = 0; i < str.length(); i++) {
		if (str[i] == '"') {
			if (isQuote == 0) {
				isQuote = 1;
			} else {
				isQuote = 0;
			}
		} else if (isQuote == 0) {
			while (str[i] == ' ' || str[i] == '\t') { // if we are not inside "" we delete the spaces
				str.erase(i, 1);
			}
			if (str[i] == '"') {
				isQuote = 1;
			}
		}
	}
	return str;
}


void Lexer::lexCondition(std::list<std::string> * lst, std::string str){

  if (signed(str.find("=="))!=-1) {
    lst->push_back(delete_spaces(str.substr(0, str.find("=="))));
    lst->push_back("==");
    str = str.substr(str.find("==")+2, str.length());
    lst->push_back(delete_spaces(str.substr(0, str.length()-1)));
  } else if (signed(str.find("<="))!=-1) {
    lst->push_back(delete_spaces(str.substr(0, str.find("<="))));
    lst->push_back("<=");
    str = str.substr(str.find("<=")+2, str.length());
    lst->push_back(delete_spaces(str.substr(0, str.length()-1)));
  } else if (signed(str.find(">="))!=-1) {
    lst->push_back(delete_spaces(str.substr(0, str.find(">="))));
    lst->push_back(">=");
    str = str.substr(str.find(">=")+2, str.length());
    lst->push_back(delete_spaces(str.substr(0, str.length()-1)));
  } else if (signed(str.find("!="))!=-1) {
    lst->push_back(delete_spaces(str.substr(0, str.find("!="))));
    lst->push_back("!=");
    str = str.substr(str.find("!=")+2, str.length());
    lst->push_back(delete_spaces(str.substr(0, str.length()-1)));
  } else if (signed(str.find("<"))!=-1) {
    lst->push_back(delete_spaces(str.substr(0, str.find("<"))));
    lst->push_back("<");
    str = str.substr(str.find("<")+1, str.length());
    lst->push_back(delete_spaces(str.substr(0, str.length()-1)));
  } else if (signed(str.find(">"))!=-1) {
    lst->push_back(delete_spaces(str.substr(0, str.find(">"))));
    lst->push_back(">");
    str = str.substr(str.find(">")+1, str.length());
    lst->push_back(delete_spaces(str.substr(0, str.length()-1)));
  }
  lst->push_back("{");
}



std::list<std::string> *Lexer::lexer(std::string file_name) {
	using namespace std;
	auto lst = new list<string>();

	ifstream infile(file_name);
	string line;
	while (getline(infile, line)) { //for line in file
		string str = line;

		while (str.length() > 0) { //split the line. when str is empty we will stop
		    if(str[0] == ' ' || str[0] == '\t') {
                str = str.substr(1, str.length());
                continue;
			} else if (str[0] == '=') { // if str starts with =
				lst->push_back("=");
				str = str.substr(1, str.length());
				str = delete_spaces(str);
				lst->push_back(str);
				str = "";
				continue;
			} else if (str[0] == '}') { // if str starts with =
              lst->push_back("}");
              str = str.substr(1, str.length());
              continue;
            } else if (str.find("openDataServer(") == 0) { // if str starts with openDataServer command
				lst->push_back("openDataServer");
				str = str.substr(15, (str.length() - 16)); // parameter of openDataServer
				str = delete_spaces(str);
				lst->push_back(str);
				str = "";
				continue; // to the next line
			} else if (str.find("connectControlClient(") == 0) { //if str starts with connectControlClient command
				lst->push_back("connectControlClient");
				str = str.substr(21, (str.length() - 22));
				lst->push_back(delete_spaces(str.substr(0, str.find(","))));
				lst->push_back(delete_spaces(str.substr(str.find(",") + 1, str.length())));
				str = "";
				continue;
			} else if (str.find("var ") == 0) { //if str starts with var
				lst->push_back("var");
				str = str.substr(4, (str.length() - 4));
				int right = str.find("->");
				int left = str.find("<-");
				int arrow = max(left, right);
				if (arrow == -1) {
					continue; //we will lex it as a put command
				}
				lst->push_back(delete_spaces(str.substr(0, arrow)));
				lst->push_back(delete_spaces(str.substr(arrow, 2)));
				str = str.substr(arrow + 2, str.length());
				continue;
			} else if (str.find("sim(") == 0) { //if str starts with sim
				lst->push_back("sim");
				str = str.substr(4, (str.length() - 5));
				lst->push_back(delete_spaces(str));
				str = "";
				continue;
			} else if (str.find("Print(") == 0) { //if str starts with print command
				lst->push_back("Print");
				str = str.substr(6, (str.length() - 7));
				lst->push_back(delete_spaces(str));
				str = "";
				continue;
			} else if (str.find("Sleep(") == 0) { //if str starts with print command
              lst->push_back("Sleep");
              str = str.substr(6, (str.length() - 7));
              lst->push_back(delete_spaces(str));
              str = "";
              continue;
            } else if (str.find("while") == 0) { //if str starts with print command
              lst->push_back("while");
              str = str.substr(5, (str.length() - 5));
              lexCondition(lst, str);
              str = "";
              continue;
            } else if (str.find("if") == 0) { //if str starts with print command
              lst->push_back("if");
              str = str.substr(2, (str.length() - 2));
              lexCondition(lst, str);
              str = "";
              continue;
            } else if (str.find("->") == 0 || str.find("<-") == 0) { //if str starts with -> or <-
				lst->push_back(str.substr(0, 2));
				str = str.substr(2, (str.length() - 2));
				continue;
			} else if (signed(str.find("="))!=-1) {
              lst->push_back(delete_spaces(str.substr(0, str.find("="))));
              str = str.substr(str.find("="), str.length());
              continue;
			} else {
		      throw "invalid line";
		    }
		}
	}
	return lst;
}
