#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_comboBox_currentIndexChanged(int index);
    void on_comboBox_2_currentIndexChanged();
    void on_horizontalSlider_valueChanged(int value);
    void on_verticalSlider_valueChanged(int value);
    void on_horizontalScrollBar_valueChanged(int value);
    void on_verticalScrollBar_valueChanged(int value);
    void on_dial_valueChanged(int value);
    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;

    // 동 초기값들을 저장해서 사용할
    QString dong_list[12];
};
#endif // MAINWINDOW_H
