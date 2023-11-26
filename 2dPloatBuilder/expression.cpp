#include "expression.h"

Expression::Expression(const QString &expression = "") {
    setExpression(expression);
}

QString Expression::getExpression() const {
    return expression;
}

void Expression::setExpression(const QString &expression) {
    this->expression = expression;
}
