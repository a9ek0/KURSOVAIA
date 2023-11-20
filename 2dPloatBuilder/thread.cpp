/*#include "thread.h"

Thread::Thread(QObject *parent) : QThread(parent)
{
}

void Thread::setFunctionToRun(const std::function<void()> &function)
{
    functionToRun = function;
}

void Thread::run()
{
    if (functionToRun)
        functionToRun();

    emit threadStarted();
}*/
