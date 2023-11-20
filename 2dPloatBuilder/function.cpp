#include "function.h"

//Function::Function(){}

Function::Function(const QString &expression) : Parser(expression){

}
// 2 operators - error
// unarn operations
double Function::calculateFunction(double x)
{
    bool trigan = false;
    double result = 0;
    QString num;

    QRegularExpression re("\\s* \\s*");
    QStringList tokens = expression.split(re);
    tokens.removeAll("");

    QStack<QString> operator_stack;
    QStack<QString> variables_stack;

    variables_stack.push(0);
    foreach (QString token, tokens) {
        if (token.contains(QRegularExpression("[cos sin ctg tg log lg sqrt fabs]"))) { //--exp
            variables_stack.push(QString::number(calcualteTriganometry(token, variables_stack.pop().toDouble())));
        } else if(token.contains(QRegularExpression("[+\\-*/]"))){
            result = variables_stack.pop().toDouble();

            if(token == '+'){
                variables_stack.push(QString::number(variables_stack.pop().toDouble() + result));
            } else if(token == '-'){
                variables_stack.push(QString::number(variables_stack.pop().toDouble() - result));
            } else if(token == '*'){
                variables_stack.push(QString::number(variables_stack.pop().toDouble() * result));
            } else if(token == '/'){
                variables_stack.push(QString::number(variables_stack.pop().toDouble() / result));
            }
        } else {
            if(token == 'x') {
                variables_stack.push(QString::number(x));
                continue;
            }
            variables_stack.push(token);
        }
    }

    result = variables_stack.pop().toDouble();
    if (variables_stack.top().contains(QRegularExpression("[cos sin ctg tg log lg sqrt fabs neg]"))) { //--exp
        result = calcualteTriganometry(variables_stack.pop(), result);
    }


    //result = variables_stack.pop().toDouble();
    //qDebug() << this->expression;
    return result;
}

double Function::calcualteTriganometry(QString function, double operand) {
    if (function == "cos") {
        return qCos(operand);
    } else if (function == "sin") {
        return qSin(operand);
    } else if (function == "ctg") {
        return qAtan(operand);
    } else if (function == "tg") {
        return qTan(operand);
    } else if (function == "exp") {
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



//lg(x) * sin(x) и sin(x) * lg(x) - разные резы и хуево скобки считает думает что lg(x * sin(x))
