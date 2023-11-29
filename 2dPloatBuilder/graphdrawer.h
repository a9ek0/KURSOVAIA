#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H
#pragma once

#include <QTimer>
#include <QThread>
#include <QLayout>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsItemGroup>

#include <cmath>

#include "function.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GraphDrawer; }
QT_END_NAMESPACE

class GraphDrawer : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphDrawer(QWidget *parent = 0);
    QPen getPenColor();
    void setMinBoarder(double minBoarder);
    void setMaxBoarder(double maxBoarder);
    void setPenColor(int color);
    void setPointsNum(int pointsNum);
    void setDrawStep(double drawStep);
    void drawPlot(QLayout *ploatLayout, Function *func, double drawStep, int pointsNum, int multyPloats);
    void numberAxes(double yMaxBoarder, double yMinBoarder);
    void saveImage(QString fileName);
    double getMinBoarder();
    double getMaxBoarder();
    double getMinYBoarder();
    double getMaxYBoarder();
    double getIndentX();
    double getIndnetY();
    double getOffsetX();
    double getOffsetY();
    double getXScaling();
    double getYScaling();
    void drawToAxesLane(double x1, double y1, double x2, double y2, int color);
    void setToAxesNumbers(double x, double y, double xNum, double yNum);
    void delToAxesLaneNumbers();
    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
    ~GraphDrawer();

public slots:
    void slotAlarmTimer();

private:
    QVector<QGraphicsLineItem*> lines;
    QGraphicsItemGroup          *group_1;
    QGraphicsItemGroup          *group_2;
    QGraphicsItemGroup          *group_3;
    QGraphicsItemGroup          *group_4;
    QGraphicsScene              *scene;
    QTimer                      *timer;

private:
    void resizeEvent(QResizeEvent *event);

private:
    double minBoarder           = 0;
    double maxBoarder           = 0;
    double minYBoarder          = 0;
    double maxYBoarder          = 0;

private:
    int width                   = 520;
    int height                  = 420;
    int penColor                = 0;
    double offsetx              = 0;
    double offsety              = 0;
    double xScaling             = 0;
    double yScaling             = 0;
    double indentX              = 0;
    double indentY              = 0;

};

#endif // MYGRAPHICVIEW_H
