#include "ploatbuilder.h"

#include <QApplication>

#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ploatBuilder w;
    w.show();
    return a.exec();
}
