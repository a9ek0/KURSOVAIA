#include "parser.h"
Parser::Parser(const QString &expression) {}

QString Parser::toPostfix(QString expression)
{
    QString error;
    QString normalized_str;

    //Set priority
    priority["+"] = 1;
    priority["-"] = 1;
    priority["*"] = 2;
    priority["/"] = 2;

    //Preparing an expression
    expression = expression.toLower();
    expression.replace(QRegularExpression("\\s+"), "");

    expression = replaceAllOccurrences(expression, "+", " + ");
    expression = replaceAllOccurrences(expression, "-", " - ");
    expression = replaceAllOccurrences(expression, "*", " * ");
    expression = replaceAllOccurrences(expression, "/", " / ");
    expression = replaceAllOccurrences(expression, "(", " ( ");
    expression = replaceAllOccurrences(expression, ")", " ) ");
    expression = replaceAllOccurrences(expression, "^", " ^ ");
    expression = replaceAllOccurrences(expression, "cos", "cos ");
    expression = replaceAllOccurrences(expression, "sin", "sin ");
    expression = replaceAllOccurrences(expression, "ctg", "ctg ");
    expression = replaceAllOccurrences(expression, "tg", "tg ");
    expression = replaceAllOccurrences(expression, "pi", "p ");
    expression = replaceAllOccurrences(expression, "exp", "xp ");
    expression = replaceAllOccurrences(expression, "e", "e ");
    expression = replaceAllOccurrences(expression, "log", "log ");
    expression = replaceAllOccurrences(expression, "lg", "lg ");
    expression = replaceAllOccurrences(expression, "sqrt", "sqrt ");
    expression = replaceAllOccurrences(expression, "fabs", "fabs ");

    QRegularExpression re("\\s* \\s*");

    QStringList tokens = expression.split(re);
    tokens.removeAll("");

    QStack<QString> operatorStack;
    QString previousToken   = " ";

    QStack<QString> mathStack;
    QString mathExpr        = " ";

    int brace               = 0;

    //Generating a postfix notation of a given expression
    foreach (QString token, tokens) {
        validateToken(token);

        if(token.contains(QRegularExpression("cos|sin|ctg|tg|log|lg|sqrt|fabs|xp"))){ //--exp
            previousToken = token;
            if(mathExpr != " "){
                mathStack.push(mathExpr);
            }
            mathExpr = token;
        }
        if(token.contains(QRegularExpression("[(]"))){
            if(previousToken == "^")
                operatorStack.push("^");

            operatorStack.push("(");
            brace++;
            previousToken = "(";
        } else if(token.contains(QRegularExpression("[)]")) && brace > 0){
            if(previousToken == "(") {
                error = "Проверьте скобки!";
                throw error;
            }
            while (operatorStack.top() != "(") {
                normalized_str += operatorStack.pop();
                normalized_str += ' ';
            }

            operatorStack.pop();
            brace--;

            if(!operatorStack.isEmpty() && operatorStack.top() == "^"){
                normalized_str += operatorStack.pop();
                normalized_str += ' ';
            }

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
            if(previousToken.contains(QRegularExpression("[+\\-*/]"))){
                error = "Проверьте знаки!";
                throw error;
            }

            while (!operatorStack.isEmpty() && (priority[token] <= priority[operatorStack.top()])) {
                normalized_str += operatorStack.pop();
                normalized_str += ' ';
            }

            if(token.contains(QRegularExpression("[+\\*/)]")) && previousToken == "(") {
                error = "Проверьте знаки!";
                throw error;
            } else if(token == "-" && previousToken == "("){
                operatorStack.push("neg");
                previousToken = "neg";
                continue;
            }

            previousToken = token;


            operatorStack.push(token);

        } else{
            if(!token.contains(QRegularExpression("cos|sin|ctg|tg|log|lg|sqrt|fabs|xp"))){
                if(token == 'p') {
                    normalized_str += QString::number(M_PI);
                    normalized_str += ' ';
                    previousToken = 'p';
                    continue;
                } else if(token == 'e') {
                    normalized_str += QString::number(M_E);
                    normalized_str += ' ';
                    previousToken = 'e';
                    continue;
                } else if(token == '^') {
                    if(previousToken == "(") {
                        error = "Проверьте знаки";
                        throw error;
                    }
                    previousToken = '^';
                    continue;
                } else {
                    normalized_str += token;
                    normalized_str += ' ';
                    if(previousToken == "neg"){
                        operatorStack.pop();
                        normalized_str += "neg";
                        normalized_str += ' ';
                    }
                    if(previousToken == '^'){
                        normalized_str += '^';
                        normalized_str += ' ';
                    }
                }
                previousToken = token;
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

    qDebug() << normalized_str;
    return normalized_str;
}

Expression* Parser::getFXExpression() const{
    return fXExpression;
}

Expression* Parser::getGXExpression() const{
    return gXExpression;
}

void Parser::validateToken(QString token)
{
    bool isDouble = false;
    QString error = "Проверьте ввод!";

    token.toDouble(&isDouble);
    if(isDouble == false){
        if (!token.contains(QRegularExpression("cos|sin|tg|ctg|fabs|sqrt|lg|log|xp|p|e|x|\\+|\\-|\\*|\\(|\\)|\\/|\\^")))
            throw error;
    } else
        return;
}

QString Parser::calculateInBracers(QStringList tokens){

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
