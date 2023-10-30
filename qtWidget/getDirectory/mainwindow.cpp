#include <QFileDialog>
#include <QDebug>
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


void MainWindow::on_pushButton_clicked()
{
    // 폴더열기 : QFileDialog::getExistingDirectory(부모객체, 창 이름, 시작 위치, 옵션)
    QString searchLocation = QFileDialog::getExistingDirectory(this, "Search Folder", QDir::homePath(), QFileDialog::ShowDirsOnly);

    // 폴더경로얻기
    qDebug() << searchLocation;
}

