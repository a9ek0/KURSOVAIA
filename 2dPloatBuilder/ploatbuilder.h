#ifndef PLOATBUILDER_H
#define PLOATBUILDER_H
#pragma once

#include <QMainWindow>

#include <QPixMap>
#include <QLayout>
#include <QValidator>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLayoutItem>
#include <QFileDialog>
#include <QImageWriter>
#include <QMouseEvent>
#include <QtConcurrent/QtConcurrent>
#include <QtPrintSupport/QPrintDialog>

#include "parser.h"
#include "deltoid.h"
#include "function.h"
#include "cardioid.h"
#include "parameters.h"
#include "graphdrawer.h"
#include "ploat.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ploatBuilder; }
QT_END_NAMESPACE

class ploatBuilder : public QMainWindow, public Ploat
{
    Q_OBJECT

public:
    ploatBuilder(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent *event);
    void setGraphicsColor(int color);
    void setData(QString fXFunction, QString gXFunction, int graphicsColor, int pointsNum, double drawStep,
                 double minBoarder, double maxBoarder, bool multyPloats);
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
    void on_comboBox_currentIndexChanged(int index);
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_radius_editingFinished();
    void on_ploatInput_editingFinished();

    void on_prompt_clicked();

    void on_ploatInput_textChanged(const QString &arg1);

public slots:
    void receiveData(int color, int pointsNum, double drawStep);

private:
    Ui::ploatBuilder  *ui;
    GraphDrawer       *plot;
    Function          *func;

private:
    QString errorMsg  = "Ошибка!";

private:
   // int graphicsColor;
   // int pointsNum;
   // bool multyPloats;
   // double drawStep;

private:
    Parameters        *parametersWindow;

//Ploats
private:
    Cardioid          *cardioid;
    Deltoid           *deltoid;

private:
    QIntValidator *intValidator;
    QDoubleValidator *doubleValidator;
};
#endif // PLOATBUILDER_H
