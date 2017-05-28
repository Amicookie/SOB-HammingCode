/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *StartButton;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *RandomBoxer;
    QLabel *label_3;
    QPushButton *RandomButton;
    QLCDNumber *insert;
    QCheckBox *checkBox;
    QPushButton *Quit;
    QSpinBox *spinBox;
    QLabel *label_4;
    QLCDNumber *lcdNumber;
    QLabel *label_5;
    QLineEdit *PoleTekstowe;
    QLineEdit *PoleRezultatu;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(640, 480));
        MainWindow->setMaximumSize(QSize(640, 480));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        StartButton = new QPushButton(centralWidget);
        StartButton->setObjectName(QStringLiteral("StartButton"));
        StartButton->setGeometry(QRect(60, 230, 71, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 471, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 170, 171, 16));
        RandomBoxer = new QSpinBox(centralWidget);
        RandomBoxer->setObjectName(QStringLiteral("RandomBoxer"));
        RandomBoxer->setGeometry(QRect(10, 310, 171, 31));
        RandomBoxer->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 290, 171, 20));
        RandomButton = new QPushButton(centralWidget);
        RandomButton->setObjectName(QStringLiteral("RandomButton"));
        RandomButton->setGeometry(QRect(60, 350, 71, 31));
        insert = new QLCDNumber(centralWidget);
        insert->setObjectName(QStringLiteral("insert"));
        insert->setGeometry(QRect(10, 120, 171, 41));
        insert->setDigitCount(8);
        insert->setMode(QLCDNumber::Bin);
        insert->setSegmentStyle(QLCDNumber::Flat);
        insert->setProperty("intValue", QVariant(248));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 400, 101, 21));
        Quit = new QPushButton(centralWidget);
        Quit->setObjectName(QStringLiteral("Quit"));
        Quit->setGeometry(QRect(550, 410, 75, 23));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(110, 400, 42, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 200, 131, 131));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../build-Hamming-Desktop_Qt_5_6_2_MinGW_32bit-Debug/Hamming.png")));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(450, 120, 171, 41));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(450, 170, 171, 20));
        PoleTekstowe = new QLineEdit(centralWidget);
        PoleTekstowe->setObjectName(QStringLiteral("PoleTekstowe"));
        PoleTekstowe->setGeometry(QRect(10, 190, 171, 31));
        PoleRezultatu = new QLineEdit(centralWidget);
        PoleRezultatu->setObjectName(QStringLiteral("PoleRezultatu"));
        PoleRezultatu->setGeometry(QRect(450, 190, 171, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Algorytm Hamminga", 0));
        StartButton->setText(QApplication::translate("MainWindow", "START", 0));
        label->setText(QApplication::translate("MainWindow", "Witaj w programie: Algorytm Hamminga", 0));
        label_2->setText(QApplication::translate("MainWindow", "Podaj ci\304\205g binarny", 0));
        label_3->setText(QApplication::translate("MainWindow", "Albo podaj d\305\202ugo\305\233\304\207 randomowego", 0));
        RandomButton->setText(QApplication::translate("MainWindow", "RANDOM", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Obecno\305\233\304\207 b\305\202\304\231du", 0));
        Quit->setText(QApplication::translate("MainWindow", "Wyj\305\233cie", 0));
        label_4->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Wynik Programu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
