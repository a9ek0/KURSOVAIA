#include "ploatbuilder.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ploatBuilder w;
    w.show();
    return a.exec();
}
//сделать отдельный класс для параметров графика

//считает не ту скобку окончательной там где возведение в квадрат 1*(1 - sqrt(1-(x/1)^2))

// добавить окно для справочной информации

// exp

//нужно регать когда график будет слишком большим и выдавать ошибку
