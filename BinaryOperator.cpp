//
// Created by חן גולדשטיין on 10/11/2019.
//

#include "BinaryOperator.h"

BinaryOperator::BinaryOperator(Expression *left, Expression *right) {
  this->left = left;
  this->right = right;
}

BinaryOperator::~BinaryOperator() {
  delete this->left;
  delete this->right;
}