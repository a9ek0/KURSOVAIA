#include "ploatbuilder.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ploatBuilder w;
    w.show();
    return a.exec();
}
