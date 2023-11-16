/********************************************************************************
** Form generated from reading UI file 'parameters.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERS_H
#define UI_PARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Parameters
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *drawStep;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *pointsNum;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *Colors;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Parameters)
    {
        if (Parameters->objectName().isEmpty())
            Parameters->setObjectName("Parameters");
        Parameters->resize(320, 240);
        Parameters->setMinimumSize(QSize(320, 240));
        Parameters->setMaximumSize(QSize(320, 240));
        verticalLayout = new QVBoxLayout(Parameters);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton = new QPushButton(Parameters);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(1, 0));
        pushButton->setMaximumSize(QSize(50, 16777215));
        pushButton->setCursor(QCursor(Qt::ArrowCursor));
        pushButton->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(Parameters);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        drawStep = new QLineEdit(Parameters);
        drawStep->setObjectName("drawStep");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(drawStep->sizePolicy().hasHeightForWidth());
        drawStep->setSizePolicy(sizePolicy1);
        drawStep->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(drawStep);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(Parameters);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        pointsNum = new QLineEdit(Parameters);
        pointsNum->setObjectName("pointsNum");
        sizePolicy1.setHeightForWidth(pointsNum->sizePolicy().hasHeightForWidth());
        pointsNum->setSizePolicy(sizePolicy1);
        pointsNum->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(pointsNum);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(Parameters);
        label_2->setObjectName("label_2");
        label_2->setEnabled(true);

        horizontalLayout->addWidget(label_2);

        Colors = new QComboBox(Parameters);
        Colors->addItem(QString());
        Colors->addItem(QString());
        Colors->addItem(QString());
        Colors->addItem(QString());
        Colors->addItem(QString());
        Colors->setObjectName("Colors");
        Colors->setEnabled(true);
        Colors->setMaximumSize(QSize(75, 16777215));

        horizontalLayout->addWidget(Colors);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(Parameters);

        QMetaObject::connectSlotsByName(Parameters);
    } // setupUi

    void retranslateUi(QDialog *Parameters)
    {
        Parameters->setWindowTitle(QCoreApplication::translate("Parameters", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Parameters", "Ok", nullptr));
        label_3->setText(QCoreApplication::translate("Parameters", "Draw step", nullptr));
        drawStep->setInputMask(QString());
        drawStep->setText(QCoreApplication::translate("Parameters", "0.03", nullptr));
        drawStep->setPlaceholderText(QString());
        label->setText(QCoreApplication::translate("Parameters", "Number of ploated points", nullptr));
        pointsNum->setInputMask(QString());
        pointsNum->setText(QCoreApplication::translate("Parameters", "800", nullptr));
        pointsNum->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("Parameters", "Graphics color", nullptr));
        Colors->setItemText(0, QCoreApplication::translate("Parameters", "Black", nullptr));
        Colors->setItemText(1, QCoreApplication::translate("Parameters", "Blue", nullptr));
        Colors->setItemText(2, QCoreApplication::translate("Parameters", "Green", nullptr));
        Colors->setItemText(3, QCoreApplication::translate("Parameters", "Red", nullptr));
        Colors->setItemText(4, QCoreApplication::translate("Parameters", "Yellow", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Parameters: public Ui_Parameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERS_H
