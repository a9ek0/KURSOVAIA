#include "ploatbuilder.h"
#include "ui_ploatbuilder.h"

ploatBuilder::ploatBuilder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ploatBuilder)
{
    ui->setupUi(this);

    plot   = new GraphDrawer();
    ui->GRAPH->addWidget(plot);
}

void ploatBuilder::setGraphicsColor(int color)
{
    this->graphicsColor = color;
}

ploatBuilder::~ploatBuilder()
{
    delete ui;
}


void ploatBuilder::on_buildButton_clicked()
{
    plot->setMinBoarder(ui->minRange->text().toDouble());
    plot->setMaxBoarder(ui->maxRange->text().toDouble());

    if(ui->function->text().isEmpty() || ui->minRange->text().isEmpty() || ui->maxRange->text().isEmpty() ||
       plot->getMinBoarder() > plot->getMaxBoarder() || plot->getMinBoarder() == plot->getMaxBoarder()){
        errorMsg = "Проверьте поля ввода!";
        QMessageBox::critical(nullptr, "Ошибка", errorMsg);
        return;
    }

    func = new Function("");
    func->getFXExpression()->setExpression(ui->function->text());
    try {
        func->getFXExpression()->setExpression(func->toPostfix(func->getFXExpression()->getExpression()));
        if(!ui->function_2->text().isEmpty()){
            func->getGXExpression()->setExpression(ui->function_2->text());
            func->getGXExpression()->setExpression(func->toPostfix(func->getGXExpression()->getExpression()));
        }
    } catch(QString &error){
        QMessageBox::critical(nullptr, "Ошибка", error); return;
    }

    //M
    if(func->getFXExpression()->getExpression() == " "){
        qDebug() << "1";
        QMessageBox::critical(nullptr, "Ошибка", errorMsg);
        return;
    }

    plot->setPenColor(graphicsColor);

    plot->drawPlot(ui->GRAPH, func, drawStep, pointsNum, multyPloats);
    ui->GRAPH->addWidget(plot);

    ui->comboBox->setCurrentIndex(0);
}


void ploatBuilder::on_actionSave_triggered()
{
    QString currentFile;
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    plot->saveImage(currentFile + ".png");
    file.close();
}


void ploatBuilder::on_actionSave_ploat_triggered()
{
    QString currentFile;
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName + ".pb");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    out << ui->function->text() << '\n' << ui->minRange->text() << '\n' << ui->maxRange->text()
        << '\n' << this->graphicsColor << '\n' << ((ui->multyPloats->checkState() == Qt::Checked) ? 1 : 0)
        << '\n' << this->drawStep << '\n' << this->pointsNum << "\n" << ui->function_2->text();
    file.close();
}


void ploatBuilder::on_actionopen_triggered()
{
    QString currentFile;
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file", QString(), "My Files (*.pb)");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);

    QTextStream in(&file);

    int lineCount = 0;
    while (lineCount < 8) {
        QString line = in.readLine();
        switch(lineCount){
        case 0:
            ui->function->setText(line);
            break;
        case 1:
            ui->minRange->setText(line);
            break;
        case 2:
            ui->maxRange->setText(line);
            break;
        case 3:
            setGraphicsColor(line.toInt());
            break;
        case 4:
            if(line.toInt() == 1){
                ui->multyPloats->setChecked(true);
            } else
                ui->multyPloats->setChecked(false);
            break;
        case 5:
            this->drawStep  = line.toDouble();
            break;
        case 6:
            this->pointsNum = line.toInt();
            break;
        case 7:
            ui->function_2->setText(line);
            break;
        }

        lineCount++;
    }

    file.close();
}


void ploatBuilder::on_actionBlack_triggered()
{
    setGraphicsColor(0);
}


void ploatBuilder::on_actionBlue_triggered()
{
    setGraphicsColor(1);
}


void ploatBuilder::on_actionGreen_triggered()
{
    setGraphicsColor(2);
}


void ploatBuilder::on_actionRed_triggered()
{
    setGraphicsColor(3);
}


void ploatBuilder::on_actionYellow_triggered()
{
    setGraphicsColor(4);
}


void ploatBuilder::on_actionParameters_triggered()
{
    parametersWindow = new Parameters(this);
    parametersWindow->setColor(this->graphicsColor);
    parametersWindow->setDrawStep(this->drawStep);
    parametersWindow->setPointsNum(this->pointsNum);
    parametersWindow->show();

    connect(parametersWindow, &Parameters::sendData, this, &ploatBuilder::receiveData);
}

void ploatBuilder::receiveData(int color, int pointsNum, double drawStep)
{
    this->graphicsColor = color;
    this->drawStep = drawStep;
    this->pointsNum = pointsNum;
}

void ploatBuilder::on_multyPloats_stateChanged(int arg1)
{
    this->multyPloats = arg1;
}

void ploatBuilder::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->ploatInput->setText("1");
        ui->ploatInput->setMaximumWidth(0);
        setGraphicsColor(0);
        ui->minRange->setText(QString::number(-10));
        ui->maxRange->setText(QString::number(10));
        ui->function->setText(" ");
        ui->function_2->setText(" ");
        ui->function->setPlaceholderText("cos(x) + 2");
        ui->function_2->setPlaceholderText("sin(x)");
        ui->multyPloats->setChecked(false);
        this->drawStep  = 0.01;
        this->pointsNum = 50;
        break;
    case 1:
        ui->ploatInput->setMaximumWidth(115);
        cardioid = new Cardioid(ui->ploatInput->text().toDouble());
        setGraphicsColor(cardioid->getGraphicsColor());
        ui->function->setText(cardioid->getFXFunction());
        ui->function_2->setText(cardioid->getGXFunction());
        ui->minRange->setText(QString::number(cardioid->getMinBoarder()));
        ui->maxRange->setText(QString::number(cardioid->getMaxBoarder()));
        ui->multyPloats->setChecked(cardioid->getMultyPloats());
        this->drawStep  = cardioid->getDrawStep();
        this->pointsNum = cardioid->getPointsNum();
        break;
    case 2:
        ui->ploatInput->setMaximumWidth(115);
        deltoid = new Deltoid(ui->ploatInput->text().toDouble());
        setGraphicsColor(deltoid->getGraphicsColor());
        ui->function->setText(deltoid->getFXFunction());
        ui->function_2->setText(deltoid->getGXFunction());
        ui->minRange->setText(QString::number(deltoid->getMinBoarder()));
        ui->maxRange->setText(QString::number(deltoid->getMaxBoarder()));
        ui->multyPloats->setChecked(deltoid->getMultyPloats());
        this->drawStep  = deltoid->getDrawStep();
        this->pointsNum = deltoid->getPointsNum();
        break;
    default:
        break;
    }

}
void ploatBuilder::on_radius_editingFinished()
{

}


void ploatBuilder::on_comboBox_currentTextChanged(const QString &arg1)
{

}


void ploatBuilder::on_ploatInput_editingFinished()
{
    switch (ui->comboBox->currentIndex()) {
    case 0:
        break;
    case 1:
        cardioid = new Cardioid(ui->ploatInput->text().toDouble());
        setGraphicsColor(cardioid->getGraphicsColor());
        ui->function->setText(cardioid->getFXFunction());
        ui->function_2->setText(cardioid->getGXFunction());
        ui->minRange->setText(QString::number(cardioid->getMinBoarder()));
        ui->maxRange->setText(QString::number(cardioid->getMaxBoarder()));
        ui->multyPloats->setChecked(cardioid->getMultyPloats());
        this->drawStep  = cardioid->getDrawStep();
        this->pointsNum = cardioid->getPointsNum();
        break;
    case 2:
        deltoid = new Deltoid(ui->ploatInput->text().toDouble());
        setGraphicsColor(deltoid->getGraphicsColor());
        ui->function->setText(deltoid->getFXFunction());
        ui->function_2->setText(deltoid->getGXFunction());
        ui->minRange->setText(QString::number(deltoid->getMinBoarder()));
        ui->maxRange->setText(QString::number(deltoid->getMaxBoarder()));
        ui->multyPloats->setChecked(deltoid->getMultyPloats());
        this->drawStep  = deltoid->getDrawStep();
        this->pointsNum = deltoid->getPointsNum();
    default:
        break;
    }
}

