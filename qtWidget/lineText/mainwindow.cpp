#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Input
void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText("hello");
}

// Del
void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->setText("");
}

// close
void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

