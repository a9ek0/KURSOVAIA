#ifndef PARSER_H
#define PARSER_H


#include <QRegularExpression>
#include <QStringList>
#include <QMessageBox>
#include <QMainWindow>
#include <QLineEdit>
#include <QStack.h>
#include <QString>
#include <QVector>
#include <QTimer>
#include <QTmath>
#include <QChar>
#include <QMap>

#include <cmath>
#include <cstring>
#include <cstdlib>

#include <map>

#include "expression.h"

QString replaceAllOccurrences(const QString& input, const QString& target, const QString& replacement);

//class Parser : public Expression
class Parser
{
public:
    Parser(const QString &expression);
    QString calculateInBracers(QStringList tokens);
    QString toPostfix(QString expression);
    Expression* getFXExpression() const;
    Expression* getGXExpression() const;
    bool validateExpression();


protected:
    std::map<QString, unsigned> priority;
    Expression *fXExpression      = new Expression("");
    Expression *gXExpression      = new Expression("");
    //QString                     expression;
};

#endif // PARSER_H
