#pragma once
#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "QString"

class Expression
{
public:
    Expression(const QString &expression);
    QString getExpression() const;
    void setExpression(const QString &expression);

protected:
    QString expression;
};

#endif // EXPRESSION_H
