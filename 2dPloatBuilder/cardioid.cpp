#include "cardioid.h"

Cardioid::Cardioid(double radius, QString fXFunction, QString gXFunction, double minBoarder,double maxBoarder, double drawStep,
                   int graphicsColor, int pointsNum, bool multyPloats) : Ploat(fXFunction, gXFunction, -2 * radius, 2 * radius,
                   0.01, 0, 20, false) {
    this->radius        = radius;
    this->fXFunction    = QString::number(radius) + " * (1 - sin(x + pi / 2)) * sin(x + pi / 2) + 0.4";
    this->gXFunction    = QString::number(radius) + " * (1 - sin(x + pi / 2)) * cos(x + pi / 2)";
}
