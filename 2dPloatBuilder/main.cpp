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
//улучшить масштабирование по максимальному числу по y
//ошибка при двойных операторах
//добавить унарные
//оси непрвильно
