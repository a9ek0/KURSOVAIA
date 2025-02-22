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
    group_4 = new QGraphicsItemGroup();

    scene->addItem(group_1);
    scene->addItem(group_2);
    scene->addItem(group_3);
    scene->addItem(group_4);

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



void GraphDrawer::drawPlot(QLayout *ploatLayout, Function *func, double drawStep, int pointsNum, int multyPloats){
    //Clear plot
    if(multyPloats == 0)
        this->deleteItemsFromGroup(group_2);

    QPen pen(Qt::blue);
    QString error = "";

    std::vector<double>  yVector(pointsNum / drawStep);
    yScaling             = 0;
    double ytmp          = 0;
    double y             = 0;
    maxYBoarder          = -__DBL_MAX__;
    minYBoarder          = __DBL_MAX__;

    xScaling      = fabs((width  - 20)/ ((fabs(maxBoarder) + fabs(minBoarder))));
    double scaledX       = 0;
    double xtmp          = minBoarder;

    //Calculating X
    indentX = minBoarder > 0 ? fabs(fabs(maxBoarder) - fabs(minBoarder)) / 10 : minBoarder < 0 && maxBoarder < 0 ? fabs(fabs(maxBoarder) - fabs(minBoarder)) / 10 : (fabs(maxBoarder) + fabs(minBoarder)) / 10;
    for(double i = maxBoarder; i > -maxBoarder; i-=indentX ){
        if(i < 1){
            break;
        }
    }

    offsetx = (fabs(maxBoarder) / indentX * 50);

    //Calculating y
    for(double x = -pointsNum / 2, i = 0; x < pointsNum / 2; x += drawStep , i++){
        try{
        yVector[i] = func->calculateFunction(x, func->getFXExpression()->getExpression());
        } catch(QString &error){
            throw error;
        }
        if(yVector[i] > maxYBoarder)
            maxYBoarder = yVector[i];

        if(yVector[i] < minYBoarder)
            minYBoarder = yVector[i];

    }

    //The grpah goes beyond the possible limits
    if(fabs(minYBoarder) > ((fabs(minBoarder) == 0 ? fabs(maxBoarder) : fabs(minBoarder)) * 10) || (fabs(maxYBoarder) > (fabs(maxBoarder) == 0 ? fabs(minBoarder) : fabs(maxBoarder)) * 10))
    {
        error = "\nизменените максимальную \nграницу на " + QString::number((maxBoarder / fabs(maxBoarder))*ceil(fabs(maxYBoarder) / 10)) + ", ";
        error += "\nи минимальную на " + QString::number((minBoarder / fabs(minBoarder))*ceil(fabs(minYBoarder) / 10)) + "!";

        QMessageBox::warning(nullptr, "Предупреждение", "При некорректном \nотображении графика" + error, "Ок");
    }



    //Situation when the graph is a horizontal line
    if(maxYBoarder == minYBoarder) {
        maxYBoarder += maxYBoarder == 0 ? 1 : fabs(maxYBoarder);
        minYBoarder -= minYBoarder == 0 ? 1 : fabs(minYBoarder);
    }

    maxYBoarder = ceil(maxYBoarder);
    minYBoarder = floor(minYBoarder);

    //Calculating the maximum and minimum y-axis border for proper scaling
    maxYBoarder = fabs(maxYBoarder) >= (fabs(maxBoarder) == 0 ? fabs(minBoarder) : fabs(maxBoarder)) * 10 ? maxBoarder * 10 : maxYBoarder;
    minYBoarder = fabs(minYBoarder) >= (fabs(minBoarder) == 0 ? fabs(maxBoarder) : fabs(minBoarder)) * 10 ? minBoarder * 10 : minYBoarder;

    indentY = minYBoarder > 0 ? fabs(fabs(maxYBoarder) - fabs(minYBoarder)) / 8 : minYBoarder < 0 && maxYBoarder < 0 ? fabs(fabs(maxYBoarder) - fabs(minYBoarder)) / 8 : (fabs(maxYBoarder) + fabs(minYBoarder)) / 8;
    for(double i = maxYBoarder; i > -maxYBoarder; i-=indentY ){
        if(i < 1){
            break;
        }
    }

    offsety = (fabs(maxYBoarder) / indentY * 50);



    yScaling = fabs((height - 20) / ((fabs(maxYBoarder) + fabs(minYBoarder))));

    //Draw axes
    pen.setWidth(0.5);
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::gray);
    group_2->addToGroup(scene->addLine(width - (maxBoarder >= 0 ? offsetx : (-offsetx)), 0, width - (maxBoarder >= 0 ? offsetx : -offsetx), height - 20, pen));
    group_2->addToGroup(scene->addLine(20, height - (height - (maxYBoarder >= 0 ? offsety : -offsety)), width, height - (height - (maxYBoarder >= 0 ? offsety : -offsety)), pen));

    //Draw plot
    pen.setWidth(1);
    pen = getPenColor();

    for(double x = -pointsNum / 2, i = 0; x < pointsNum / 2; x += drawStep , i++){
        y = yVector[i];

        scaledX = ((func->getGXExpression()->getExpression() == "" ? x
        : func->calculateFunction(x, func->getGXExpression()->getExpression()))  * xScaling);

        y *= -yScaling;

    //Draw Lines
        if(scaledX > -((width - 20) - offsetx) && scaledX < offsetx  && i > 0 && y > (/*minBoarder*/minYBoarder == 0 ? 1 : /*maxBoarder*/maxYBoarder == 0 ? -1 : 1)*(y - offsety) && y < ((height - 20) - offsety))
            group_2->addToGroup(scene->addLine(scaledX + width - (maxBoarder >= 0 ? offsetx : -offsetx), ytmp + (maxYBoarder >= 0 ? offsety : -offsety), xtmp + width - (maxBoarder >= 0 ? offsetx : -offsetx), y + (maxYBoarder >= 0 ? offsety : -offsety), pen));

        xtmp = scaledX;
        ytmp = y;

    }

    pen.setColor(Qt::white);
    pen.setWidth(20);
    group_2->addToGroup(scene->addLine(30, -11, width + 20, -11, pen));
    group_2->addToGroup(scene->addLine(width + 12, -11, width + 12, height - 25, pen));
    pen.setWidth(28);
    group_2->addToGroup(scene->addLine(5, -11, 5, height - 25, pen));
    group_2->addToGroup(scene->addLine(30, height - 4, width + 20, height - 4, pen));

    numberAxes(maxYBoarder, minYBoarder);

}

void GraphDrawer::numberAxes(double yMaxBoarder, double yMinBoarder)
{
    //Delete numbers from plot
    this->deleteItemsFromGroup(group_3);

    double minX   = fabs(minBoarder);
    double maxX   = fabs(maxBoarder);
    double minY   = fabs(yMinBoarder);
    double maxY   = fabs(yMaxBoarder);

    QString text;
    QGraphicsTextItem *numberItem;

    //Сalculation of numbers based on the minimum and maximum boundaries and installation on a chart
    //For x
    indentX = minBoarder > 0 ? fabs(maxX - minX) / 10 : minBoarder < 0 && maxBoarder < 0 ? fabs(maxX - minX) / 10 : (maxX + minX) / 10;
    for(double i = maxBoarder, j = 0; j < 11; i -= indentX, j++){
        text = QString::number(round(i * 10.0) / 10.0);

        numberItem = new QGraphicsTextItem(text);
        numberItem->setPos((width - 50 * j) - 10, height - 20);

        group_3->addToGroup(numberItem);
    }

    //For y
    indentY = yMinBoarder > 0 ? fabs(maxY - minY) / 8 : yMinBoarder < 0 && yMaxBoarder < 0 ? fabs(maxY - minY) / 8 : (maxY + minY) / 8;
    for(double i = yMaxBoarder, j = 0; j < 9; i -= indentY, j++){
        text = QString::number(round(i * 10.0) / 10.0);

        numberItem = new QGraphicsTextItem(text);
        numberItem->setPos(-10, (50 * j) - 12);

        group_3->addToGroup(numberItem);
    }

}

void GraphDrawer::saveImage(QString fileName)
{
    //Copying the current chart, scaling, saving and restoring the current chart
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

double GraphDrawer::getMinYBoarder()
{
    return minYBoarder;
}

double GraphDrawer::getMaxYBoarder()
{
    return maxYBoarder;
}

double GraphDrawer::getIndentX()
{
    return this->indentX;
}

double GraphDrawer::getIndnetY()
{
    return this->indentY;
}

double GraphDrawer::getOffsetX()
{
    return this->offsetx;
}

double GraphDrawer::getOffsetY()
{
    return this->offsety;
}

double GraphDrawer::getXScaling()
{
    return this->xScaling;
}

double GraphDrawer::getYScaling()
{
    return this->yScaling;
}



void GraphDrawer::drawToAxesLane(double x1, double y1, double x2, double y2, int color)
{
    QPen pen;

    switch (color) {
    case 0:
        pen.setColor(Qt::red);
        break;
    case 1:
        pen.setColor(Qt::green);
        break;
    default:
        pen.setColor(Qt::red);
        break;
    }

    pen.setWidth(0.5);
    pen.setStyle(Qt::DashLine);
    pen.setDashOffset(10);

    group_4->addToGroup(scene->addLine(x1, y1, x2, y2, pen));
}

void GraphDrawer::setToAxesNumbers(double x, double y, double xNum, double yNum)
{
    QGraphicsTextItem *numberItem;


    numberItem = new QGraphicsTextItem(QString::number(yNum));
    numberItem->setDefaultTextColor(QColor(Qt::green));
    numberItem->setPos(-10, y - 72.5);
    group_4->addToGroup(numberItem);

    numberItem = new QGraphicsTextItem(QString::number(xNum));
    numberItem->setDefaultTextColor(QColor(Qt::red));
    numberItem->setPos(x - 270, 400);
    group_4->addToGroup(numberItem);
}

void GraphDrawer::delToAxesLaneNumbers()
{
    this->deleteItemsFromGroup(group_4);
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


    // Net
    QPen pen(Qt::black);
    pen.setWidth(0.3);
    pen.setColor(Qt::gray);
    pen.setStyle(Qt::DotLine);

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
