#include "parser.h"
Parser::Parser(const QString &expression) : expression(expression) {}

void Parser::setExpression(const QString &expression)
{
    this->expression = expression;
}

QString Parser::getExpression() const
{
    return expression;
}

void Parser::toPostfix()
{
    QString error;
    QString normalized_str;


    priority["+"] = 1;
    priority["-"] = 1;
    priority["*"] = 2;
    priority["/"] = 2;

    this->expression = expression.toLower();
    expression.replace(QRegularExpression("\\s+"), "");

    this->expression = replaceAllOccurrences(expression, "+", " + ");
    this->expression = replaceAllOccurrences(expression, "-", " - ");
    this->expression = replaceAllOccurrences(expression, "*", " * ");
    this->expression = replaceAllOccurrences(expression, "/", " / ");
    this->expression = replaceAllOccurrences(expression, "(", " ( ");
    this->expression = replaceAllOccurrences(expression, ")", " ) ");
    this->expression = replaceAllOccurrences(expression, "cos", "cos ");
    this->expression = replaceAllOccurrences(expression, "sin", "sin ");
    this->expression = replaceAllOccurrences(expression, "ctg", "ctg ");
    this->expression = replaceAllOccurrences(expression, "tg", "tg ");
    this->expression = replaceAllOccurrences(expression, "p", "p ");
    this->expression = replaceAllOccurrences(expression, "e", "e ");
    this->expression = replaceAllOccurrences(expression, "exp", "exp ");
    this->expression = replaceAllOccurrences(expression, "log", "log ");
    this->expression = replaceAllOccurrences(expression, "lg", "lg ");
    this->expression = replaceAllOccurrences(expression, "sqrt", "sqrt ");
    this->expression = replaceAllOccurrences(expression, "fabs", "fabs ");

    QRegularExpression re("\\s* \\s*");
    QStringList tokens = expression.split(re);
    tokens.removeAll("");
    //dobavit unarnie operatori
    QStack<QString> operator_stack;
    QStack<QString> tang_stack;
    int brace = 0;
    QString tang = " ";
    foreach (QString token, tokens) {
        if(token.contains(QRegularExpression("[cos sin ctg tg log lg sqrt fabs]"))){ //--exp
            if(tang != " "){
                tang_stack.push(tang);
            }
            tang = token;
        }
        if(token.contains(QRegularExpression("[(]"))){
            operator_stack.push("(");
            brace++;
        } else if(token.contains(QRegularExpression("[)]")) && brace > 0){
            while (operator_stack.top() != "(") {
                normalized_str += operator_stack.pop();
                normalized_str += ' ';
            }

            operator_stack.pop();
            brace--;

            if(tang != " "){
                normalized_str += tang;
                normalized_str += ' ';
                tang = " ";
                if(!tang_stack.empty()){
                    tang = tang_stack.pop();
                }
                continue;
            }

        } else if(token.contains(QRegularExpression("[+\\-*/)]"))){
            while (!operator_stack.isEmpty() && (priority[token] <= priority[operator_stack.top()])) {
                normalized_str += operator_stack.pop();
                normalized_str += ' ';
            }
            operator_stack.push(token);

        } else{
            if(!token.contains(QRegularExpression("[cos sin ctg tg log lg sqrt fabs]"))){
                if(token == "p") {
                    normalized_str += QString::number(M_PI);
                    normalized_str += ' ';
                    continue;
                } else if(token == 'e') {
                    normalized_str += QString::number(M_E);
                    normalized_str += ' ';
                    continue;
                } else {
                    normalized_str += token;
                    normalized_str += ' ';
                }
            }
        }
    }

    if(normalized_str.isEmpty()){
        error = "Ошибка!";
        throw error;
    }

    while (!operator_stack.isEmpty()) {
        if(operator_stack.top() == "(" || operator_stack.top() == ")"){
            error = "Проверьте скобки!";
            throw error;
        }
        normalized_str.append(operator_stack.top());
        operator_stack.pop();
        normalized_str += ' ';
    }

    this->expression = normalized_str;
    qDebug() << this->expression;
}

double Parser::calculateFunction()
{
    double res = 0;



    return res;
}

QString Parser::getFunction()
{
    return this->expression;
}

QString Parser::calculateInBracers(QStringList tokens)
{

}

QString replaceAllOccurrences(const QString& input, const QString& target, const QString& replacement) {
    QString result = input;
    int index = result.indexOf(target);
    while (index != -1) {
        result.replace(index, target.length(), replacement);
        index = result.indexOf(target, index + replacement.length());
    }
    return result;
}
