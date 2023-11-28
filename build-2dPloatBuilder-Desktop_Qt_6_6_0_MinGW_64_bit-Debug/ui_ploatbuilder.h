/********************************************************************************
** Form generated from reading UI file 'ploatbuilder.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOATBUILDER_H
#define UI_PLOATBUILDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ploatBuilder
{
public:
    QAction *actionSave;
    QAction *actionSave_ploat;
    QAction *actionopen;
    QAction *actionBlack;
    QAction *actionBlue;
    QAction *actionGreen;
    QAction *actionRed;
    QAction *actionYellow;
    QAction *actionDraw_step;
    QAction *actionNumber_of_plotted_points;
    QAction *actionAnimations;
    QAction *actionDot_labels;
    QAction *actionParameters;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *function;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QLineEdit *function_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QLineEdit *ploatInput;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *minRange;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *maxRange;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *multyPloats;
    QPushButton *prompt;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *buildButton;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *GRAPH;
    QLabel *mouseLabel;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSetings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ploatBuilder)
    {
        if (ploatBuilder->objectName().isEmpty())
            ploatBuilder->setObjectName("ploatBuilder");
        ploatBuilder->setEnabled(true);
        ploatBuilder->resize(810, 540);
        ploatBuilder->setMinimumSize(QSize(810, 540));
        ploatBuilder->setMaximumSize(QSize(810, 540));
        actionSave = new QAction(ploatBuilder);
        actionSave->setObjectName("actionSave");
        actionSave_ploat = new QAction(ploatBuilder);
        actionSave_ploat->setObjectName("actionSave_ploat");
        actionopen = new QAction(ploatBuilder);
        actionopen->setObjectName("actionopen");
        actionBlack = new QAction(ploatBuilder);
        actionBlack->setObjectName("actionBlack");
        actionBlue = new QAction(ploatBuilder);
        actionBlue->setObjectName("actionBlue");
        actionGreen = new QAction(ploatBuilder);
        actionGreen->setObjectName("actionGreen");
        actionRed = new QAction(ploatBuilder);
        actionRed->setObjectName("actionRed");
        actionYellow = new QAction(ploatBuilder);
        actionYellow->setObjectName("actionYellow");
        actionDraw_step = new QAction(ploatBuilder);
        actionDraw_step->setObjectName("actionDraw_step");
        actionNumber_of_plotted_points = new QAction(ploatBuilder);
        actionNumber_of_plotted_points->setObjectName("actionNumber_of_plotted_points");
        actionAnimations = new QAction(ploatBuilder);
        actionAnimations->setObjectName("actionAnimations");
        actionDot_labels = new QAction(ploatBuilder);
        actionDot_labels->setObjectName("actionDot_labels");
        actionParameters = new QAction(ploatBuilder);
        actionParameters->setObjectName("actionParameters");
        centralwidget = new QWidget(ploatBuilder);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 231, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout_3->addWidget(label);

        function = new QLineEdit(verticalLayoutWidget);
        function->setObjectName("function");
        function->setMaximumSize(QSize(185, 16777215));

        horizontalLayout_3->addWidget(function);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_9->addWidget(label_2);

        function_2 = new QLineEdit(verticalLayoutWidget);
        function_2->setObjectName("function_2");
        function_2->setMaximumSize(QSize(185, 16777215));

        horizontalLayout_9->addWidget(function_2);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(115, 0));
        comboBox->setMaximumSize(QSize(115, 100));

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ploatInput = new QLineEdit(verticalLayoutWidget);
        ploatInput->setObjectName("ploatInput");
        ploatInput->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ploatInput->sizePolicy().hasHeightForWidth());
        ploatInput->setSizePolicy(sizePolicy);
        ploatInput->setMaximumSize(QSize(115, 100));
        ploatInput->setLayoutDirection(Qt::RightToLeft);
        ploatInput->setFrame(true);
        ploatInput->setEchoMode(QLineEdit::Normal);

        horizontalLayout_2->addWidget(ploatInput);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_5->addWidget(label_4);

        minRange = new QLineEdit(verticalLayoutWidget);
        minRange->setObjectName("minRange");
        sizePolicy.setHeightForWidth(minRange->sizePolicy().hasHeightForWidth());
        minRange->setSizePolicy(sizePolicy);
        minRange->setMaximumSize(QSize(185, 16777215));
        minRange->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_5->addWidget(minRange);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(35, 16777215));

        horizontalLayout_6->addWidget(label_5);

        maxRange = new QLineEdit(verticalLayoutWidget);
        maxRange->setObjectName("maxRange");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(maxRange->sizePolicy().hasHeightForWidth());
        maxRange->setSizePolicy(sizePolicy2);
        maxRange->setMaximumSize(QSize(185, 16777215));

        horizontalLayout_6->addWidget(maxRange);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        multyPloats = new QCheckBox(verticalLayoutWidget);
        multyPloats->setObjectName("multyPloats");
        multyPloats->setChecked(false);

        horizontalLayout_4->addWidget(multyPloats);

        prompt = new QPushButton(verticalLayoutWidget);
        prompt->setObjectName("prompt");
        prompt->setMaximumSize(QSize(20, 16777215));
        prompt->setCursor(QCursor(Qt::WhatsThisCursor));
        prompt->setMouseTracking(true);
        prompt->setToolTipDuration(-100);
        prompt->setCheckable(true);
        prompt->setChecked(false);
        prompt->setAutoDefault(false);
        prompt->setFlat(true);

        horizontalLayout_4->addWidget(prompt);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buildButton = new QPushButton(verticalLayoutWidget);
        buildButton->setObjectName("buildButton");
        sizePolicy.setHeightForWidth(buildButton->sizePolicy().hasHeightForWidth());
        buildButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(buildButton);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(250, 20, 551, 451));
        GRAPH = new QVBoxLayout(verticalLayoutWidget_2);
        GRAPH->setObjectName("GRAPH");
        GRAPH->setContentsMargins(0, 0, 0, 0);
        mouseLabel = new QLabel(centralwidget);
        mouseLabel->setObjectName("mouseLabel");
        mouseLabel->setGeometry(QRect(250, 480, 49, 16));
        ploatBuilder->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ploatBuilder);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 810, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuSetings = new QMenu(menubar);
        menuSetings->setObjectName("menuSetings");
        ploatBuilder->setMenuBar(menubar);
        statusbar = new QStatusBar(ploatBuilder);
        statusbar->setObjectName("statusbar");
        ploatBuilder->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSetings->menuAction());
        menuFile->addAction(actionopen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_ploat);
        menuSetings->addAction(actionParameters);

        retranslateUi(ploatBuilder);

        prompt->setDefault(false);


        QMetaObject::connectSlotsByName(ploatBuilder);
    } // setupUi

    void retranslateUi(QMainWindow *ploatBuilder)
    {
        ploatBuilder->setWindowTitle(QCoreApplication::translate("ploatBuilder", "ploatBuilder", nullptr));
        actionSave->setText(QCoreApplication::translate("ploatBuilder", "Save image", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("ploatBuilder", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_ploat->setText(QCoreApplication::translate("ploatBuilder", "Save ploat", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_ploat->setShortcut(QCoreApplication::translate("ploatBuilder", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionopen->setText(QCoreApplication::translate("ploatBuilder", "Open", nullptr));
        actionBlack->setText(QCoreApplication::translate("ploatBuilder", "Black", nullptr));
        actionBlue->setText(QCoreApplication::translate("ploatBuilder", "Blue", nullptr));
        actionGreen->setText(QCoreApplication::translate("ploatBuilder", "Green", nullptr));
        actionRed->setText(QCoreApplication::translate("ploatBuilder", "Red", nullptr));
        actionYellow->setText(QCoreApplication::translate("ploatBuilder", "Yellow", nullptr));
        actionDraw_step->setText(QCoreApplication::translate("ploatBuilder", "Draw step", nullptr));
        actionNumber_of_plotted_points->setText(QCoreApplication::translate("ploatBuilder", "Number of plotted points", nullptr));
        actionAnimations->setText(QCoreApplication::translate("ploatBuilder", "Animations", nullptr));
        actionDot_labels->setText(QCoreApplication::translate("ploatBuilder", "Dot labels", nullptr));
        actionParameters->setText(QCoreApplication::translate("ploatBuilder", "Parameters", nullptr));
        label->setText(QCoreApplication::translate("ploatBuilder", "f(x) =", nullptr));
        function->setInputMask(QString());
        function->setText(QString());
        function->setPlaceholderText(QCoreApplication::translate("ploatBuilder", "cos(\321\205) + 2", nullptr));
        label_2->setText(QCoreApplication::translate("ploatBuilder", "g(x) =", nullptr));
        function_2->setInputMask(QString());
        function_2->setText(QString());
        function_2->setPlaceholderText(QCoreApplication::translate("ploatBuilder", "sin(\321\205)", nullptr));
        comboBox->setItemText(0, QString());
        comboBox->setItemText(1, QCoreApplication::translate("ploatBuilder", "Cardioid", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ploatBuilder", "Deltoid", nullptr));

        ploatInput->setInputMask(QString());
        ploatInput->setText(QCoreApplication::translate("ploatBuilder", "1", nullptr));
        label_4->setText(QCoreApplication::translate("ploatBuilder", "Min =", nullptr));
        minRange->setInputMask(QString());
        minRange->setText(QCoreApplication::translate("ploatBuilder", "-10", nullptr));
        label_5->setText(QCoreApplication::translate("ploatBuilder", "Max =", nullptr));
        maxRange->setText(QCoreApplication::translate("ploatBuilder", "10", nullptr));
        multyPloats->setText(QCoreApplication::translate("ploatBuilder", "Save previous charts", nullptr));
#if QT_CONFIG(tooltip)
        prompt->setToolTip(QCoreApplication::translate("ploatBuilder", "<html><head/><body><p>\320\225\321\201\320\273\320\270 \320\262\321\213 \320\275\320\265 \320\262\320\270\320\264\320\270\321\202\320\265 \320\263\321\200\320\260\321\204\320\270\320\272, </p><p>\320\277\320\276\320\277\321\200\320\276\320\261\321\203\320\271\321\202\320\265 \321\203\320\262\320\265\320\273\320\270\321\207\320\270\321\202\321\214 \320\274\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\321\203\321\216 </p><p>\320\270 \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\321\203\321\216 \320\263\321\200\320\260\320\275\320\270\321\206\321\203.</p><p>(\320\235\320\260\320\266\320\274\320\270\321\202\320\265 \321\207\321\202\320\276\320\261\321\213 \320\267\320\260\320\272\321\200\321\213\321\202\321\214 \320\277\320\276\320\264\321\201\320\272\320\260\320\267\320\272\321\203.)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        prompt->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        prompt->setText(QCoreApplication::translate("ploatBuilder", "!", nullptr));
        buildButton->setText(QCoreApplication::translate("ploatBuilder", "Build", nullptr));
        mouseLabel->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("ploatBuilder", "File", nullptr));
        menuSetings->setTitle(QCoreApplication::translate("ploatBuilder", "Setings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ploatBuilder: public Ui_ploatBuilder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOATBUILDER_H
