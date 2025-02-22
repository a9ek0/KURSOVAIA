#include "ploatbuilder.h"
#include "ui_ploatbuilder.h"


ploatBuilder::ploatBuilder(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ploatBuilder)
{
    ui->setupUi(this);

    plot            = new GraphDrawer();
    ui->GRAPH->addWidget(plot);

    ui->ploatInput->setVisible(false);
    ui->prompt->setVisible(false);
    ui->label_3->setVisible(false);


    intValidator    = new QIntValidator();
    doubleValidator = new QDoubleValidator();

    ui->minRange->setValidator(intValidator);
    ui->maxRange->setValidator(intValidator);
    ui->ploatInput->setValidator(doubleValidator);

    setMouseTracking(true);
    ui->centralwidget->setMouseTracking(true);
    ui->mouseLabel->setMouseTracking(true);

  /*QPixmap bkgnd("C:/Users/Alexander/Desktop/1669096676_photochki-pro-p-tyanki-v-trusikakh-erotika-instagram-2.jpg");
    bkgnd = bkgnd.scaled(QSize(810, 550), Qt::KeepAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette); */
}

void ploatBuilder::mouseMoveEvent(QMouseEvent *event)
{
    QString text;
    double x = 0;
    double y = 0;
    //Shows the coordinate of a point on the graph
    if(event->pos().x() >= 280 && event->pos().x() <= 780 && event->pos().y() >= 60 && event->pos().y() <= 460 && ui->label_3->isVisible()){
        plot->delToAxesLaneNumbers();
        x = -((500 - (event->pos().x() - 280)) / (50 / plot->getIndentX()) - plot->getMaxBoarder());
        y = -((event->pos().y() - 60) / (50 / plot->getIndnetY()) - plot->getMaxYBoarder());

        plot->drawToAxesLane(event->pos().x() - 260, event->pos().y() - 60, 20, event->pos().y() - 60, 1);
        plot->drawToAxesLane(event->pos().x() - 260, event->pos().y() - 60, event->pos().x() - 260, 400, 0);
        plot->setToAxesNumbers(event->pos().x(), event->pos().y(), round(x * 10) / 10, round(y * 10) / 10);
    } else{
        plot->delToAxesLaneNumbers();
    }
}

void ploatBuilder::setGraphicsColor(int color)
{
    this->graphicsColor = color;
}

void ploatBuilder::setData(QString fXFunction, QString gXFunction, int graphicsColor, int pointsNum, double drawStep, double minBoarder, double maxBoarder, bool multyPloats)
{
    setGraphicsColor(graphicsColor);

    ui->function->setText(fXFunction);
    ui->function_2->setText(gXFunction);

    ui->minRange->setText(QString::number(minBoarder));
    ui->maxRange->setText(QString::number(maxBoarder));

    //ui->multyPloats->setChecked(multyPloats);

    this->drawStep  = drawStep;
    this->pointsNum = pointsNum;
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
        plot->setPenColor(graphicsColor);
        plot->drawPlot(ui->GRAPH, func, drawStep, pointsNum, multyPloats);
    } catch(QString &error){
        QMessageBox::critical(nullptr, "Ошибка", error); return;
    } catch(...) {
        QMessageBox::critical(nullptr, "Ошибка", "Неизвестная ошибка!"); return;
    }

    ui->GRAPH->addWidget(plot);

    ui->prompt->setVisible(true);
    ui->label_3->setVisible(true);
}


void ploatBuilder::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }

    plot->saveImage(fileName + ".png");
    file.close();
}


void ploatBuilder::on_actionSave_ploat_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName + ".pb");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }

    QFileInfo currentFile(fileName);
    setWindowTitle(currentFile.baseName());

    QTextStream out(&file);
    out << ui->function->text() << '\n' << ui->minRange->text() << '\n' << ui->maxRange->text()
        << '\n' << this->graphicsColor << '\n' << ((ui->multyPloats->checkState() == Qt::Checked) ? 1 : 0)
        << '\n' << this->drawStep << '\n' << this->pointsNum << "\n" << ui->function_2->text();
    file.close();
}


void ploatBuilder::on_actionopen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file", QString(), "My Files (*.pb)");
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }

    QFileInfo currentFile(fileName);
    setWindowTitle(currentFile.baseName());

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
    bool readOnly = (index  == 0 ? false : true);
    ui->function->setReadOnly(readOnly);
    ui->function_2->setReadOnly(readOnly);
    ui->minRange->setReadOnly(readOnly);
    ui->maxRange->setReadOnly(readOnly);

    switch (index) {
    case 0:
        //Возможно удалять не стоит
        ui->ploatInput->setText("1");
        ui->ploatInput->setVisible(false);

        setData("", "", 0, 50, 0.01, -10, 10, false);

        break;
    case 1:
        ui->ploatInput->setVisible(true);
        cardioid = new Cardioid(ui->ploatInput->text().toDouble());

        setData(cardioid->getFXFunction(), cardioid->getGXFunction(), cardioid->getGraphicsColor(), cardioid->getPointsNum(),
                cardioid->getDrawStep(), cardioid->getMinBoarder(), cardioid->getMaxBoarder(), cardioid->getMultyPloats());

        break;
    case 2:
        ui->ploatInput->setVisible(true);
        deltoid = new Deltoid(ui->ploatInput->text().toDouble());

        setData(deltoid->getFXFunction(), deltoid->getGXFunction(), deltoid->getGraphicsColor(), deltoid->getPointsNum(),
                deltoid->getDrawStep(), deltoid->getMinBoarder(), deltoid->getMaxBoarder(), deltoid->getMultyPloats());

        break;
    default:
        break;
    }

    ui->function->setCursorPosition(0);
    ui->function_2->setCursorPosition(0);

}


void ploatBuilder::on_ploatInput_editingFinished()
{
    switch (ui->comboBox->currentIndex()) {
    case 0:
        break;
    case 1:
        cardioid = new Cardioid(ui->ploatInput->text().toDouble());

        setData(cardioid->getFXFunction(), cardioid->getGXFunction(), cardioid->getGraphicsColor(), cardioid->getPointsNum(),
                cardioid->getDrawStep(), cardioid->getMinBoarder(), cardioid->getMaxBoarder(), cardioid->getMultyPloats());

        break;
    case 2:
        deltoid = new Deltoid(ui->ploatInput->text().toDouble());

        setData(deltoid->getFXFunction(), deltoid->getGXFunction(), deltoid->getGraphicsColor(), deltoid->getPointsNum(),
                deltoid->getDrawStep(), deltoid->getMinBoarder(), deltoid->getMaxBoarder(), deltoid->getMultyPloats());

        break;
    default:
        break;
    }

    ui->function->setCursorPosition(0);
    ui->function_2->setCursorPosition(0);

    ui->ploatInput->clearFocus();
}

void ploatBuilder::on_radius_editingFinished()
{

}


void ploatBuilder::on_comboBox_currentTextChanged(const QString &arg1)
{

}

void ploatBuilder::on_prompt_clicked()
{
    ui->prompt->setVisible(false);
}


void ploatBuilder::on_ploatInput_textChanged(const QString &arg1)
{
    switch (ui->comboBox->currentIndex()) {
    case 0:
        break;
    case 1:
        cardioid = new Cardioid(ui->ploatInput->text().toDouble());

        setData(cardioid->getFXFunction(), cardioid->getGXFunction(), cardioid->getGraphicsColor(), cardioid->getPointsNum(),
                cardioid->getDrawStep(), cardioid->getMinBoarder(), cardioid->getMaxBoarder(), cardioid->getMultyPloats());

        break;
    case 2:
        deltoid = new Deltoid(ui->ploatInput->text().toDouble());

        setData(deltoid->getFXFunction(), deltoid->getGXFunction(), deltoid->getGraphicsColor(), deltoid->getPointsNum(),
                deltoid->getDrawStep(), deltoid->getMinBoarder(), deltoid->getMaxBoarder(), deltoid->getMultyPloats());

        break;
    default:
        break;
    }

    ui->function->setCursorPosition(0);
    ui->function_2->setCursorPosition(0);

    //ui->ploatInput->clearFocus();
}



