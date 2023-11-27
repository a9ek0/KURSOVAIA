#include "deltoid.h"

Deltoid::Deltoid(double size, QString fXFunction, QString gXFunction, double minBoarder,double maxBoarder, double drawStep,
                 int graphicsColor, int pointsNum, bool multyPloats) : Ploat(fXFunction, gXFunction, -3 * size, 3 * size,
                 0.01, 0, 20, false) {
    this->size          = size;
    this->fXFunction    = "2 * " + QString::number(size) + " * cos(x) + " + QString::number(size) + " * cos(2 * x)";
    this->gXFunction    = "2 * " + QString::number(size) + " * sin(x) - " + QString::number(size) + " * sin(2 * x)";
}

//x   2 * A * cos(x) + A * cos(2 * x)
//y   2 * A * sin(x) - A * sin(2 * x)
