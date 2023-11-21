#ifndef PARSER_H
#define PARSER_H

#include <QString>

#include <QMainWindow>
#include <QLineEdit>
#include <QMessageBox>
#include <QTimer>
#include <QTmath>
#include <QString>
#include <QVector>
#include <QRegularExpression>
#include <QStringList>
#include <QStack.h>
#include <QChar>
#include <QMap>

#include <cmath>
#include <map>

#include <cstring>
#include <cstdlib>


QString replaceAllOccurrences(const QString& input, const QString& target, const QString& replacement);

class Parser
{
public:
    Parser(const QString &expression);
    QString getExpression() const;
    QString getFunction();
    QString calculateInBracers(QStringList tokens);
    void setExpression(const QString &expression);
    void toPostfix();
    bool validateExpression();


protected:
    std::map<QString, unsigned> priority;
    QString                     expression;
};

#endif // PARSER_H
