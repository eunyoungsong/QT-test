#include <QDebug>
#include <iostream>
#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Hello");
    std::cout << "cout test!!" << std::endl;
    qDebug() << "debug test!!";

    qint8 one = 123;
    qDebug() << "int:" << one;
    qDebug() << "Qsting:" << QString::number(one);
}

MainWindow::~MainWindow()
{
    delete ui;
}

