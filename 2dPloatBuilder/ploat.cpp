#include "ploat.h"

Ploat::Ploat(QString fXFunction, QString gXFunction, double minBoarder, double maxBoarder,
             double drawStep, int graphicsColor, int pointsNum, bool multyPloats) {
    this->graphicsColor = graphicsColor;
    this->multyPloats   = multyPloats;
    this->fXFunction    = fXFunction;
    this->gXFunction    = gXFunction;
    this->minBoarder    = minBoarder;
    this->maxBoarder    = maxBoarder;
    this->pointsNum     = pointsNum;
    this->drawStep      = drawStep;
}

QString Ploat::getFXFunction() {
    return this->fXFunction;
}

QString Ploat::getGXFunction() {
    return this->gXFunction;
}

double Ploat::getMinBoarder() {
    return this->minBoarder;
}

double Ploat::getMaxBoarder() {
    return this->maxBoarder;
}

double Ploat::getDrawStep() {
    return this->drawStep;
}

bool Ploat::getMultyPloats() {
    return this->multyPloats;
}

int Ploat::getGraphicsColor() {
    return this->graphicsColor;
}

int Ploat::getPointsNum() {
    return this->pointsNum;
}

void Ploat::setFXFunction(QString fXFunction) {
    this->fXFunction = fXFunction;
}

void Ploat::setGXFunction(QString gXFunction) {
    this->gXFunction = gXFunction;
}

void Ploat::setMinBoarder(double minBoarder) {
    this->minBoarder = minBoarder;
}

void Ploat::setMaxBoarder(double maxBoarder) {
    this->maxBoarder = maxBoarder;
}

void Ploat::setDrawStep(double drawStep) {
    this->drawStep = drawStep;
}

void Ploat::setMultyPloats(bool multyPloats) {
    this->multyPloats = multyPloats;
}

void Ploat::setGraphicsColor(int graphicsColor) {
    this->graphicsColor = graphicsColor;
}

void Ploat::setPointsNum(int pointsNum) {
    this->pointsNum = pointsNum;
}
