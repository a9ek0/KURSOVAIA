#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QDialog>

namespace Ui {
class Parameters;
}

class Parameters : public QDialog
{
    Q_OBJECT

public:
    explicit Parameters(QWidget *parent = nullptr);
    int getColor();
    int getPointsNum();
    double getdrawStep();
    void setColor(int color);
    void setPointsNum(int pointsNum);
    void setDrawStep(double drawStep);
    ~Parameters();

private slots:
    void on_pushButton_clicked();

signals:
    void sendData(int color, int pointsNum, double drawStep);

private:
    Ui::Parameters *ui;

protected:
    int color       = 0;
    int pointsNum   = 0;
    double drawStep = 0;
};

#endif // PARAMETERS_H
