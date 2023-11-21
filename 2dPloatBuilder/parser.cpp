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

    //Set priority
    priority["+"] = 1;
    priority["-"] = 1;
    priority["*"] = 2;
    priority["/"] = 2;

    //Preparing an expression
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

    QStack<QString> operatorStack;
    QString previousToken   = " ";

    QStack<QString> mathStack;
    QString mathExpr            = " ";

    int brace               = 0;

    //Generating a postfix notation of a given expression
    foreach (QString token, tokens) {
        if(token.contains(QRegularExpression("[cos sin ctg tg log lg sqrt fabs]"))){ //--exp
            previousToken = token;
            if(mathExpr != " "){
                mathStack.push(mathExpr);
            }
            mathExpr = token;
        }
        if(token.contains(QRegularExpression("[(]"))){
            operatorStack.push("(");
            brace++;
            previousToken = "(";
        } else if(token.contains(QRegularExpression("[)]")) && brace > 0){
            while (operatorStack.top() != "(") {
                normalized_str += operatorStack.pop();
                normalized_str += ' ';
            }

            operatorStack.pop();
            brace--;
            previousToken = ")";

            if(mathExpr != " "){
                normalized_str += mathExpr;
                normalized_str += ' ';
                mathExpr = " ";
                if(!mathStack.empty()){
                    mathExpr = mathStack.pop();
                }
                continue;
            }
        } else if(token.contains(QRegularExpression("[+\\-*/)]"))){
            if(previousToken.contains(QRegularExpression("[+-*/)]"))){
                error = "Проверьте знаки!";
                throw error;
            }
            while (!operatorStack.isEmpty() && (priority[token] <= priority[operatorStack.top()])) {
                normalized_str += operatorStack.pop();
                normalized_str += ' ';
            }
            if(token.contains(QRegularExpression("[+\\*/)]")) && previousToken == "(") {
                error = "2Проверьте знаки!";
                throw error;
            } else if(token == "-" && previousToken == "("){
                operatorStack.push("neg");
                continue;
            }
            previousToken = token;

            operatorStack.push(token);

        } else{
            if(!token.contains(QRegularExpression("[cos sin ctg tg log lg sqrt fabs]"))){
                previousToken = token;
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
        error = "Отсутсвует выражение!";
        throw error;
    }

    //Putting the remaining operators into a postfix expression
    while (!operatorStack.isEmpty()) {
        if(operatorStack.top() == "(" || operatorStack.top() == ")"){
            error = "Проверьте скобки!";
            throw error;
        }
        normalized_str.append(operatorStack.top());
        operatorStack.pop();
        normalized_str += ' ';
    }

    this->expression = normalized_str;
    qDebug() << this->expression;
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
