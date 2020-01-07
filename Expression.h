//
// Created by yoavst22 on 09/11/2019.
//

#ifndef PROJECT_EXPRESSION_H
#define PROJECT_EXPRESSION_H

/**
 * Expression Interface
 */
class Expression {
public:
    virtual double calculate() = 0;
    virtual ~Expression() = default;
};

#endif //PROJECT_EXPRESSION_H
