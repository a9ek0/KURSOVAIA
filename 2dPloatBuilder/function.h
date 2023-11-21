#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H

#include <cmath>
#include "parser.h"

class Function : public Parser
{
public:
    Function(const QString &expression);

    double calculateFunction(double x);
    double calcualteMath(QString func, double exp);
};

#endif // FUNCTION_H
