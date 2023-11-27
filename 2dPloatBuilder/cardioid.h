#ifndef CARDIOID_H
#define CARDIOID_H

#include "ploat.h"

class Cardioid : public Ploat
{
public:
    Cardioid(double radius, QString fXFunction = "", QString gXFunction = "",
             double minBoarder = 0, double maxBoarder = 0, double drawStep = 0,
             int graphicsColor = 0, int pointsNum = 0, bool multyPloats = false);

private:
    double radius = 0;
};
#endif // CARDIOID_H
