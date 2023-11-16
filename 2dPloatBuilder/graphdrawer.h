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

#include "Function.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GraphDrawer; }
QT_END_NAMESPACE

class GraphDrawer : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphDrawer(QWidget *parent = 0);
    void setMinBoarder(double minBoarder);
    void setMaxBoarder(double maxBoarder);
    void setPenColor(int color);
    void setPointsNum(int pointsNum);
    void setDrawStep(double drawStep);
    void drawPlot(Function *func, double drawStep, int pointsNum, int multyPloats);
    void numberAxes();
    void saveImage(QString fileName);
    double getMinBoarder();
    double getMaxBoarder();
    QPen getPenColor();

    void deleteItemsFromGroup(QGraphicsItemGroup *group_1);
    ~GraphDrawer();

signals:

private slots:
    void slotAlarmTimer();

private:
    QGraphicsScene      *scene;
    QGraphicsItemGroup  *group_1;
    QGraphicsItemGroup  *group_2;
    QGraphicsItemGroup  *group_3;
    QTimer              *timer;

private:
    void resizeEvent(QResizeEvent *event);

private:
    double minBoarder = 0;
    double maxBoarder = 0;

private:
    int width         = 520;
    int height        = 420;
    int penColor      = 0;
};

#endif // MYGRAPHICVIEW_H
