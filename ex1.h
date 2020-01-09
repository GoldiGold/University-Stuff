//
// Created by yoavst22 on 09/11/2019.
//

#ifndef ADVANCED1_HW3_EX1_H
#define ADVANCED1_HW3_EX1_H

#include <iostream>
#include <string>
#include <map>
#include <regex>
#include <utility>
#include <stack>
#include <list>
#include "Expression.h"


class Value: public Expression {
    double val;
public:
    explicit Value(double val1): val(val1) {
    }
    double calculate() override {return this->val;}
};

class Variable: public Expression {
    std::string name;
    double value;

public:
    Variable(std::string name1, double val1): name(name1), value(val1) {}

    double calculate() override {return this->value;}

    Variable &operator++();

    Variable &operator--();

    Variable &operator+=(double i);

    Variable &operator-=(double i);

    Variable &operator++(int i);

    Variable &operator--(int i);
};


class UnaryOperator: public Expression {
protected:
    Expression* exp{};
public:
    virtual ~UnaryOperator() {delete this->exp;}
};

class UPlus: public UnaryOperator {
 public:
    explicit UPlus (Expression* exp1) {this->exp = exp1;}
    double calculate() override {return this->exp->calculate();}
};

class UMinus: public UnaryOperator {
 public:
  explicit UMinus (Expression* exp1) {this->exp = exp1;}
  double calculate() override {return -this->exp->calculate();}
};


class BinaryOperator: public Expression {
 protected:
  Expression* right{};
  Expression* left{};
 public:
  virtual ~BinaryOperator() {delete this->right; delete this->left;}
};

class Plus: public BinaryOperator {
 public:
  Plus (Expression* exp1, Expression* exp2) {
    left = exp1; right = exp2;
  }
  double calculate() override {
    return left->calculate() + right->calculate();
  }
};

class Minus: public BinaryOperator {
 public:
  Minus (Expression* exp1, Expression* exp2) {
    left = exp1; right = exp2;
  }
  double calculate() override {
    return left->calculate() - right->calculate();
  }
};

class Mul: public BinaryOperator {
 public:
  Mul (Expression* exp1, Expression* exp2) {
    left = exp1; right = exp2;
  }
  double calculate() override {
    return left->calculate() * right->calculate();
  }
};

class Div: public BinaryOperator {
 public:
  Div (Expression* exp1, Expression* exp2) {
    left = exp1; right = exp2;
  }
  double calculate() override {
    if (this->right->calculate() == 0) {
      throw ("division by zero");
    }
    return left->calculate() / right->calculate();
  }
};

class Interpreter {
  std::map<std::string,double>* vars;

 public:
  Interpreter() {
    this->vars = new std::map<std::string,double>();
  }
  ~Interpreter() {
    delete this->vars;
  }

  void setVariables(std::string str);
  void setVariables(std::map<std::string,double>* m) { vars = m;}
  Expression* interpret(std::string str);
 private:
  //return the first number or operator in the string
  std::string firstPart(std::string &str);
};

#endif //ADVANCED1_HW3_EX1_H
