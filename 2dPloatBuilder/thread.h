/*#pragma once

#include <QThread>
#include "graphdrawer.h"

class Thread : public QThread
{
    Q_OBJECT

public:
    Thread(QObject *parent = nullptr);
    void setFunctionToRun(const std::function<void()> &function);
    void run() override;

signals:
    void threadStarted();

private:
    std::function<void()> functionToRun;
};*/

