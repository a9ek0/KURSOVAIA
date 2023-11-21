#ifndef PLOATBUILDER_H
#define PLOATBUILDER_H
#pragma once

#include <QMainWindow>
#include <QMessageBox>

#include <QPixMap>
#include <QLayout>
#include <QVBoxLayout>
#include <QtConcurrent/QtConcurrent>
#include <QLayoutItem>
#include <QFileDialog>
#include <QImageWriter>
#include <QtPrintSupport/QPrintDialog>

#include "graphdrawer.h"
#include "parser.h"
#include "function.h"
#include "parameters.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ploatBuilder; }
QT_END_NAMESPACE

class ploatBuilder : public QMainWindow
{
    Q_OBJECT

public:
    ploatBuilder(QWidget *parent = nullptr);
    void setGraphicsColor(int color);
    ~ploatBuilder();

private slots:
    void on_buildButton_clicked();
    void on_actionSave_triggered();
    void on_actionSave_ploat_triggered();
    void on_actionopen_triggered();
    void on_actionBlack_triggered();
    void on_actionBlue_triggered();
    void on_actionGreen_triggered();
    void on_actionRed_triggered();
    void on_actionYellow_triggered();
    void on_actionParameters_triggered();
    void on_multyPloats_stateChanged(int arg1);

public slots:
    void receiveData(int color, int pointsNum, double drawStep);

private:
    Ui::ploatBuilder  *ui;
    GraphDrawer       *plot;
    Parser            *pars;
    Function          *func;

private:
    QString errorMsg  = "Ошибка!";

private:
    int graphicsColor = 0;
    int pointsNum     = 200;
    bool multyPloats  = 0;
    double drawStep   = 0.01;

private:
    Parameters        *parametersWindow;
};
#endif // PLOATBUILDER_H
