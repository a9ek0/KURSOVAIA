#ifndef DELTOID_H
#define DELTOID_H

#include "ploat.h"

class Deltoid : public Ploat
{
public:
    Deltoid(double size, QString fXFunction = "", QString gXFunction = "",
            double minBoarder = 0, double maxBoarder = 0, double drawStep = 0,
            int graphicsColor = 0, int pointsNum = 0, bool multyPloats = false);
private:
    double size = 0;
};

#endif // DELTOID_H
