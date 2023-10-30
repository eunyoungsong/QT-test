#include <QFileDialog>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* 파일과 폴더 구분하여 출력 */
    QDir dir("/home/eunyoung/Downloads");
    foreach( QFileInfo item, dir.entryInfoList() )
    {
        if (item.isDir())
        {
            qDebug() << "Dir:" << item.absoluteFilePath(); // 폴더 출력
        }
        else if (item.isFile())
        {
            qDebug() << "File:" << item.absoluteFilePath(); // 파일 출력
        }
    }

    qDebug() << "---------------------------------------------------------------------------";

     /* 부모와 자기자신의 폴더 제거하여 출력 */
    QDir dir2("/home/eunyoung/Downloads");
    foreach( QFileInfo item, dir2.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries) )  // 옵션 추가
    {
        if (item.isDir())
        {
            qDebug() << "Dir:" << item.absoluteFilePath(); // 폴더 출력
        }
        else if (item.isFile())
        {
            qDebug() << "File:" << item.absoluteFilePath(); // 파일 출력
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

