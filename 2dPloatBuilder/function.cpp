#include "function.h"

//Function::Function(){}

Function::Function(const QString &expression) : Parser(expression){
}

double Function::calculateFunction(double x, const QString &expression)
{
    bool mathExpr      = false;
    double result      = 0;
    QString error;
    QString num;

    QRegularExpression re("\\s* \\s*");
    QStringList tokens   = expression.split(re);
    tokens.removeAll("");

    QStack<QString> variablesStack;
    variablesStack.push(0);

    //Evaluating an Expression in Postfix Form
    foreach (QString token, tokens) {
        if (token.contains(QRegularExpression("cos|sin|ctg|tg|log|lg|sqrt|fabs|xp|neg"))) {
            variablesStack.push(QString::number(calcualteMath(token, variablesStack.pop().toDouble())));
        } else if(token.contains(QRegularExpression("[+\\-*/^]"))){
            result = variablesStack.pop().toDouble();

            if(variablesStack.top() == "" && token != "-") {
                error = "Неверные операнды!";
                throw error;
            }

            if(token == '+'){
                variablesStack.push(QString::number(variablesStack.pop().toDouble() + result));
            } else if(token == '-'){
                //Case when - is the first char in function
                if(variablesStack.top() == ""){
                    variablesStack.push(QString::number(calcualteMath("neg", result)));
                    continue;
                }
                variablesStack.push(QString::number(variablesStack.pop().toDouble() - result));
            } else if(token == '*'){
                variablesStack.push(QString::number(variablesStack.pop().toDouble() * result));
            } else if(token == '/'){
                variablesStack.push(QString::number(variablesStack.pop().toDouble() / result));
            } else if(token == '^'){
                variablesStack.push(QString::number(pow(variablesStack.pop().toDouble(), result)));
            }
        } else {
            if(token == 'x') {
                variablesStack.push(QString::number(x));
                continue;
            }
            variablesStack.push(token);
        }
    }

    result = variablesStack.pop().toDouble();
    //The case when the expression contains only math expression
    if (variablesStack.top().contains(QRegularExpression("cos|sin|ctg|tg|log|lg|sqrt|fabs|neg"))) { //--exp
        result = calcualteMath(variablesStack.pop(), result);
    }

    return result;
}

double Function::calcualteMath(QString function, double operand) {
    if (function == "cos") {
        return qCos(operand);
    } else if (function == "sin") {
        return qSin(operand);
    } else if (function == "ctg") {
        return qAtan(operand);
    } else if (function == "tg") {
        return qTan(operand);
    } else if (function == "xp") {
        return qExp(operand);
    } else if (function == "log") {
        return log(operand);
    } else if (function == "lg") {
        return log10(operand);
    } else if (function == "sqrt") {
        return qSqrt(operand);
    } else if (function == "fabs") {
        return qFabs(operand);
    } else if (function == "neg") {
        return operand * (-1);
    }

    return 0.0;
}
