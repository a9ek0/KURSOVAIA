#include "graphdrawer.h"

GraphDrawer::GraphDrawer(QWidget *parent)
    : QGraphicsView(parent)
{
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setMinimumHeight(100);
    this->setMinimumWidth(100);

    scene = new QGraphicsScene();
    this->setScene(scene);

    group_1 = new QGraphicsItemGroup();
    group_2 = new QGraphicsItemGroup();
    group_3 = new QGraphicsItemGroup();

    scene->addItem(group_1);
    scene->addItem(group_2);
    scene->addItem(group_3);

    timer = new QTimer();
    timer->setSingleShot(true);

    connect(timer, SIGNAL(timeout()), this, SLOT(slotAlarmTimer()));
    timer->start(50);
}

void GraphDrawer::setMinBoarder(double minBoarder)
{
    this->minBoarder = minBoarder;
}

void GraphDrawer::setMaxBoarder(double maxBoarder)
{
    this->maxBoarder = maxBoarder;
}

void GraphDrawer::setPenColor(int color)
{
    this->penColor = color;
}



void GraphDrawer::drawPlot(Function *func, double drawStep, int pointsNum, int multyPloats)
{
    //Clear plot
    if(multyPloats == 0)
        this->deleteItemsFromGroup(group_2);

    QPen pen(Qt::blue);
    pen.setWidth(1);

    // Variables for plot scaling
    double yScaling = fabs((height - 20)/ ((fabs(maxBoarder) + fabs(minBoarder))));
    double xScaling = fabs((width  - 20)/ ((fabs(maxBoarder) + fabs(minBoarder))));

    double xtmp = minBoarder;
    double ytmp = 0;

    double scaledX = 0;
    double y = 0;
    double indent;

    double offsetx = 0;
    double offsety = 0;

    double absMaxBoarder = fabs(maxBoarder);
    double absMinBoarder = fabs(minBoarder);

    //Count to make offset
    indent = minBoarder > 0 ? fabs(absMaxBoarder - absMinBoarder) / 10 : minBoarder < 0 && maxBoarder < 0 ? fabs(absMaxBoarder - absMinBoarder) / 10 : (absMaxBoarder + absMinBoarder) / 10;
    for(double i = maxBoarder; i > -maxBoarder; i-=indent ){
        if(i < 1){
            break;
        }
    }
    offsetx = (absMaxBoarder / indent * 50);

    indent = minBoarder > 0 ? fabs(absMaxBoarder - absMinBoarder) / 8 : minBoarder < 0 && maxBoarder < 0 ? fabs(absMaxBoarder - absMinBoarder) / 8 : (absMaxBoarder + absMinBoarder) / 8;
    for(double i = maxBoarder; i > -maxBoarder; i-=indent ){
        if(i < 1){
            break;
        }
    }
    offsety = (absMaxBoarder / indent * 50);

    //Draw axes
    pen.setWidth(0.5);
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::gray);
    group_2->addToGroup(scene->addLine(width - (maxBoarder >= 0 ? offsetx : (-offsetx)), 0, width - (maxBoarder >= 0 ? offsetx : -offsetx), height - 20, pen));
    group_2->addToGroup(scene->addLine(20, height - (height - (maxBoarder >= 0 ? offsety : -offsety)), width, height - (height - (maxBoarder >= 0 ? offsety : -offsety)), pen));

    pen.setWidth(1);
    pen = getPenColor();

    //Drawing plot
    for(double x = -pointsNum / 2, i = 0; x < pointsNum / 2; x += drawStep , i++){
        // Place for parser function
        y = func->calculateFunction(x);

        scaledX = (x * xScaling);
        y *= -yScaling;

        //Draw Lines
        if(scaledX > -((width - 20) - offsetx) && scaledX < offsetx  && i > 0 && y > (minBoarder == 0 ? 1 : maxBoarder == 0 ? -1 : 1)*(y - offsety) && y < ((height - 20) - offsety))
            group_2->addToGroup(scene->addLine(scaledX + width - (maxBoarder >= 0 ? offsetx : -offsetx), ytmp + (maxBoarder >= 0 ? offsety : -offsety), xtmp + width - (maxBoarder >= 0 ? offsetx : -offsetx), y + (maxBoarder >= 0 ? offsety : -offsety), pen));

        xtmp = scaledX;
        ytmp = y;
    }
    //КОСТЫЛЬ ЛЮТЫЙ

    pen.setColor(Qt::white);
    pen.setWidth(20);
    group_2->addToGroup(scene->addLine(30, -11, width + 20, -11, pen));
    group_2->addToGroup(scene->addLine(width + 12, -11, width + 12, height - 25, pen));
    pen.setWidth(28);
    group_2->addToGroup(scene->addLine(5, -11, 5, height - 25, pen));
    group_2->addToGroup(scene->addLine(30, height - 4, width + 20, height - 4, pen));

    numberAxes();

}

void GraphDrawer::numberAxes()
{
    this->deleteItemsFromGroup(group_3);

    double indent = 0;
    double min1 = fabs(minBoarder);
    double max1 = fabs(maxBoarder);

    QString text;
    QGraphicsTextItem *numberItem;

    indent = minBoarder > 0 ? fabs(max1 - min1) / 10 : minBoarder < 0 && maxBoarder < 0 ? fabs(max1 - min1) / 10 : (max1 + min1) / 10;
    for(double i = maxBoarder, j = 0; j < 11; i -= indent, j++){
        text = QString::number(round(i * 10.0) / 10.0);
        numberItem = new QGraphicsTextItem(text);
        numberItem->setPos((width - 50 * j) - 10, height - 20);
        group_3->addToGroup(numberItem);
    }

    indent = minBoarder > 0 ? fabs(max1 - min1) / 8 : minBoarder < 0 && maxBoarder < 0 ? fabs(max1 - min1) / 8 : (max1 + min1) / 8;
    for(double i = maxBoarder, j = 0; j < 9; i -= indent, j++){
        text = QString::number(round(i * 10.0) / 10.0);
        numberItem = new QGraphicsTextItem(text);
        numberItem->setPos(-10, (50 * j) - 12);
        group_3->addToGroup(numberItem);
    }

}

void GraphDrawer::saveImage(QString fileName)
{
    QGraphicsScene *newScene = new QGraphicsScene();
    newScene->setSceneRect(-20, -20, width + 50, height + 40);

    newScene->addItem(group_1);
    newScene->addItem(group_2);
    newScene->addItem(group_3);

    QRect rect(-10, -5, width + 70, height + 50);
    QGraphicsView *view;
    view = new QGraphicsView(newScene);
    QPixmap pixMap = view->grab(rect);
    pixMap.save(fileName);

    scene->addItem(group_1);
    scene->addItem(group_2);
    scene->addItem(group_3);
}

double GraphDrawer::getMinBoarder()
{
    return minBoarder;
}

double GraphDrawer::getMaxBoarder()
{
    return maxBoarder;
}

QPen GraphDrawer::getPenColor()
{
    QPen pen;
    switch(this->penColor){
    case 0:
        pen.setColor(Qt::black);
        return pen;
    case 1:
        pen.setColor(Qt::blue);
        return pen;
    case 2:
        pen.setColor(Qt::green);
        return pen;
    case 3:
        pen.setColor(Qt::red);
        return pen;
    case 4:
        pen.setColor(Qt::yellow);
        return pen;
    default:
        pen.setColor(Qt::black);
        return pen;
    }
}

GraphDrawer::~GraphDrawer()
{
}

void GraphDrawer::slotAlarmTimer()
{
    this->deleteItemsFromGroup(group_1);
    this->deleteItemsFromGroup(group_2);

    scene->setSceneRect(5, -5, width, height);

    QPen pen(Qt::black);
    pen.setWidth(0.3);
    pen.setColor(Qt::gray);
    pen.setStyle(Qt::DotLine);

    // Net
    for(int i = 0; i < 8; i++){
        group_1->addToGroup(scene->addLine(20, (((height - 20)/ 8) * i), width, (((height - 20)/ 8) * i), pen));
    }

    for(int i = 1; i < 11; i++){
        group_1->addToGroup(scene->addLine((((width - 20) / 10) * i) + 20, 0, (((width - 20) / 10) * i) + 20, height - 20, pen));
    }

    // Side stripes
    pen.setWidth(0.5);
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::black);
    for(int i = 0; i < (height - 20); i += (height - 20) / 8){
        if(i != 0) group_1->addToGroup(scene->addLine(20, i, (width * 0.02) + 20, i, pen));

        for(int j = (height - 20) / 8 / 5; j < (height - 20) / 8; j += (height - 20) / 8 / 5){
            group_1->addToGroup(scene->addLine(20, i + j, (width * 0.005) + 20, i + j, pen));
        }

    }

    for(int i = 20; i < (width - 20); i += (width - 20) / 10){
        group_1->addToGroup(scene->addLine(i, height - 20, i, (height * 0.98) - 20, pen));

        for(int j = (width - 20) / 10 / 5; j < (width - 20) / 10; j += (width - 20) / 10 / 5){
            group_1->addToGroup(scene->addLine(i + j, (height * 0.995) - 20, i + j, height - 20, pen));
        }

    }
    //Boarders
    pen.setColor(Qt::black);
    pen.setWidth(0.3);
    //group_1->addToGroup(scene->addLine(width, 0, width, height - 20, pen));
    group_1->addToGroup(scene->addLine(20, height - 20, width, height - 20, pen));
    group_1->addToGroup(scene->addLine(20, 0, 20, height - 20, pen));

}

void GraphDrawer::resizeEvent(QResizeEvent *event)
{
    timer->start(50);
    QGraphicsView::resizeEvent(event);
}

void GraphDrawer::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    foreach( QGraphicsItem *item, scene->items(group->boundingRect())) {
        if(item->group() == group ) {
            delete item;
        }
    }
}
