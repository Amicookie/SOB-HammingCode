#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Quit_clicked()
{
    MainWindow::close();
}

void MainWindow::on_StartButton_clicked()
{
    QString v = ui->PoleTekstowe->text();
    bool ok;
    int dec = v.toInt(&ok, 10);
    if (ok==true) ui->insert->display(dec);
    int bin = v.toInt(&ok, 2);
    if (ok==true) ui->insert->display(bin);
}

void MainWindow::on_RandomButton_clicked()
{
    int number = qPow(2, ui->RandomBoxer->value());
    int randomValue = qrand() % number;
    ui->PoleTekstowe->setText(QString::number(randomValue));
    ui->insert->display(randomValue);
}
