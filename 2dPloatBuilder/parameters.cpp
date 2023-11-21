#include "parameters.h"
#include "ui_parameters.h"

Parameters::Parameters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Parameters)
{
    ui->setupUi(this);
}

int Parameters::getColor()
{
    return this->color;
}

int Parameters::getPointsNum()
{
    return this->pointsNum;
}

double Parameters::getdrawStep()
{
    return this->drawStep;
}

void Parameters::setColor(int color)
{
    ui->Colors->setCurrentIndex(color);
}

void Parameters::setPointsNum(int pointsNum)
{
    ui->pointsNum->setText(QString::number(pointsNum));
}

void Parameters::setDrawStep(double drawStep)
{
    ui->drawStep->setText(QString::number(drawStep));
}

Parameters::~Parameters()
{
    delete ui;
}

void Parameters::on_pushButton_clicked()
{
    color     = ui->Colors->currentIndex();
    pointsNum = ui->pointsNum->text().toInt();
    drawStep  = ui->drawStep->text().toDouble();

    //Transferring data to the main window
    emit sendData(color, pointsNum, drawStep);

    close();
}

