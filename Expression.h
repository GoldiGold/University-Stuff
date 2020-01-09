//
// Created by yoavst22 on 09/11/2019.
//

#ifndef ADVANCED1_HW3_EXPRESSION_H
#define ADVANCED1_HW3_EXPRESSION_H

/**
 * Expression Interface
 */
class Expression {
public:
    virtual double calculate() = 0;
    virtual ~Expression() = default;
};

#endif //ADVANCED1_HW3_EXPRESSION_H
