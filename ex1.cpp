//
// Created by yoavst22 on 09/11/2019.
//
#include "ex1.h"

Variable &Variable::operator++() {
  this->value = this->value + 1;
  return *this;
}
Variable &Variable::operator--() {
  this->value = this->value - 1;
  return *this;
}
Variable &Variable::operator+=(double i) {
  this->value = this->value + i;
  return *this;
}
Variable &Variable::operator-=(double i) {
  this->value = this->value - i;
  return *this;
}
Variable &Variable::operator++(int i) {
  this->value = this->value + 1;
  i++;
  return *this;
}
Variable &Variable::operator--(int i) {
  this->value = this->value - 1;
  i++;
  return *this;
}

// return the first number or operator or variable
std::string Interpreter::firstPart(std::string &str) {
  using namespace std;
  if (str.length() == 0) {
    throw ("empty string");
  }
  string string1;
  string c = string(1, str[0]);

  if (!c.compare("+") || !c.compare("-") || !c.compare("*")
  || !c.compare("/") || !c.compare("(") || !c.compare(")")) {
    return c;
  }

  for (unsigned int i = 0; i <= str.length(); i++) {
    try {
      this->vars->at(str.substr(0, i));
      return ("_" + str.substr(0, i));
    } catch (exception&) {}
  }

  c = str[0];
  if (0 > c.compare("0") || 9 < c.compare("0")) {
    throw ("invalid string");
  }
  int count_dot = 0;
  for (unsigned int i = 0; i < str.length() && ((0 <= c.compare("0")
  && 9 >= c.compare("0")) || (!c.compare(".") && count_dot == 0)); i++, c = str[i]) {
    string1 += c;
    if (!c.compare(".")) {
      count_dot++;
    }
  }
  return string1;
}

Expression *Interpreter::interpret(std::string str) {
  using namespace std;
  auto *s = new stack<string>;
  auto *l = new list<string>;
  string pc;
  string _str = "_";
  if (str.length() == 0) {
    delete l;
    delete s;
    throw ("empty expression");
  }

  while (str.length() > 0) {
    string c;
    try {
      c = firstPart(str);
    } catch (const char* e) {
      delete l;
      delete s;
      throw ("invalid expression");
    }
    if (!_str.compare(c.substr(0, 1))) {
      str.erase(0, c.length() - 1);
    } else {
      str.erase(0, c.length());
    }
    if(!c.compare("(")) {
      s->push(c);
    } else if(!c.compare(")")) {
      while (!s->empty() && (s->top()).compare("(")) {
        l->push_back(s->top());
        s->pop();
        if (s->empty()) {
          delete l;
          delete s;
          throw ("invalid expression");
        }
      }
      s->pop();
    } else if (!c.compare("+") || !c.compare("-")) {
      if ((l->empty() && s->empty()) || !pc.compare("(")) {
        s->push(c += "u");
      } else {
        while (!s->empty() && (s->top()).compare("(")) {
          l->push_back(s->top());
          s->pop();
        }
        s->push(c);
      }
    } else if(!c.compare("*") || !c.compare("/")) {
      while (!s->empty() && (!(s->top()).compare("*") || !(s->top()).compare("/"))) {
        l->push_back(s->top());
        s->pop();
      }
      s->push(c);
    } else {
      l->push_back(c);
    }
    pc = c;
  }
  while (!s->empty()) {
    l->push_back(s->top());
    s->pop();
  }

  auto es = new stack<Expression*>();
  for (auto v: *l) {
    if (!v.compare("+u")) {
      if (es->empty()) {
        delete l;
        delete s;
        delete es;
        throw ("invalid expression");
      }
      auto e = es->top();
      es->pop();
      es->push(new UPlus(e));
    } else if (!v.compare("-u")) {
      if (es->empty()) {
        delete l;
        delete s;
        delete es;
        throw ("invalid expression");
      }
      auto e = es->top();
      es->pop();
      es->push(new UMinus(e));
    } else if (!v.compare("+")) {
      if (es->empty() || es->size() < 2) {
        delete l;
        delete s;
        delete es;
        throw ("invalid expression");
      }
      auto e1 = es->top();
      es->pop();
      auto e2 = es->top();
      es->pop();
      es->push(new Plus(e2, e1));
    } else if (!v.compare("-")) {
      if (es->empty() || es->size() < 2) {
        delete l;
        delete s;
        delete es;
        throw ("invalid expression");
      }
      auto e1 = es->top();
      es->pop();
      auto e2 = es->top();
      es->pop();
      es->push(new Minus(e2, e1));
    } else if (!v.compare("*")) {
      if (es->empty() || es->size() < 2) {
        delete l;
        delete s;
        delete es;
        throw ("invalid expression");
      }
      auto e1 = es->top();
      es->pop();
      auto e2 = es->top();
      es->pop();
      es->push(new Mul(e2, e1));
    } else if (!v.compare("/")) {
      if (es->empty() || es->size() < 2) {
        delete l;
        delete s;
        delete es;
        throw ("invalid expression");
      }
      auto e1 = es->top();
      es->pop();
      auto e2 = es->top();
      es->pop();
      es->push(new Div(e2, e1));
    } else if(!_str.compare(v.substr(0, 1))) {
      string name = v.substr(1, v.length() - 1);
      es->push(new Variable(name, this->vars->at(name)));
    } else{
      try {
        es->push(new Value(stod(v)));
      } catch (exception&) {
        delete l;
        delete s;
        delete es;
        throw ("invalid expression");
      }
    }

  }
  if (es->empty()) {
    delete l;
    delete s;
    delete es;
    throw ("invalid expression");
  }
  auto e = es->top();
  es->pop();
  if (!es->empty()) {
    delete l;
    delete s;
    delete es;
    throw ("invalid expression");
  }
  delete l;
  delete s;
  delete es;

  return e;
}

void Interpreter::setVariables(std::string str) {
  using namespace std;
  string name;
  string v_str;
  while (str.length() > 0) {
    if (str.find(";") == string::npos && str.find_first_of("=") == str.find_last_of("=")) {
      name = str.substr(0,str.find("="));
      v_str = str.substr(str.find("=") + 1 , str.length() - str.find("="));
    } else if (str.find(";") == string::npos || str.find("=") == string::npos
    || str.find(";") -1 <= str.find("=")) {
      throw ("invalid setVariables string");
    } else {
      name = str.substr(0,str.find("="));
      v_str = str.substr(str.find("=") + 1 , str.find(";") - str.find("=") - 1);
    }

    int count_dot = 0;
    for (unsigned int i = 0; i < v_str.length(); i++) {
      char c = v_str.at(i);
      if ((c < '0' || c > '9') && c != '-' && c != '.') {
        throw ("invalid setVariables value");
      }
      if (c == '-' && i!= 0) {
        throw ("invalid setVariables value");
      }
      if (c == '.') {
        if (count_dot > 0) {
          throw ("invalid setVariables value");
        }
        count_dot++;
      }
    }
    double val;
    try {
      val = stod(v_str);
    } catch (exception&){
      throw ("invalid setVariables value");
    }

    if (!name.compare("_")) {
      throw ("invalid setVariables name");
    }
    for (unsigned int i = 0; i < name.length(); i++) {
      if (name[i] >= '0' && name[i] <= '9') {
        if (i == 0){
          throw("invalid setVariables name");
        }
      } else if (name[i] != '_' && (name[i] < 'a' || name[i] > 'z')
      && (name[i] < 'A' || name[i] > 'Z')) {
        throw("invalid setVariables name");
      }
    }

    this->vars->insert(pair<string,double>(name, val));
    map<string,double>::iterator it = this->vars->find(name);
    if (it != this->vars->end()) {
      it->second = val;
    }

    if (str.find(";") == string::npos) {
      return;
    }
    str = str.substr(str.find(";") + 1);
  }
}
