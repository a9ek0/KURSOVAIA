#ifndef PLOAT_H
#define PLOAT_H

#include "QString"

class Ploat
{
public:
    Ploat(QString fXFunction, QString gXFunction, double minBoarder, double maxBoarder, double drawStep, int graphicsColor,
          int pointsNum, bool multyPloats);
    QString getFXFunction();
    QString getGXFunction();
    double getMinBoarder();
    double getMaxBoarder();
    double getDrawStep();
    bool getMultyPloats();
    int getGraphicsColor();
    int getPointsNum();
    void setFXFunction(QString fXFunction);
    void setGXFunction(QString gXFunction);
    void setMinBoarder(double minBoarder);
    void setMaxBoarder(double maxBoarder);
    void setDrawStep(double drawStep);
    void setMultyPloats(bool multyPloats);
    void setGraphicsColor(int graphicsColor);
    void setPointsNum(int pointsNum);

protected:
    QString fXFunction;
    QString gXFunction;
    double minBoarder;
    double maxBoarder;
    double drawStep;
    bool multyPloats;
    int graphicsColor;
    int pointsNum;
};

#endif // PLOAT_H
