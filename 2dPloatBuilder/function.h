#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <QString>

#include <cmath>

#include "parser.h"
#include "expression.h"

class Function : public Parser
{
public:
    Function(const QString &expression);
    double calculateFunction(double x, const QString &expression);
    double calcualteMath(QString func, double exp);
};

#endif // FUNCTION_H
