#include <QString>
#include <QScrollBar>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 동 콤보박스에 저장되어 있는 초기 텍스트값들을 가져오는 코드
    // QString 변수에 한글을 저장해서 사용하면 깨지는데, 위젯에 있는 텍스트값을 가져와서 사용하면 깨지지않음.

    for(int i=0; i<12; i++) {
        dong_list[i] = ui->comboBox_2->itemText(i);  // 배열변수에 순서대로 아이템 넣기
    }
    /*
     * 초기화 설정
    ui->comboBox_2->clear();                        // 구 콤보박스 아이템 값들 초기화
    ui->comboBox_2->addItem(dong_list[0]);        // 초기 동에 맞춰서 구 아이템 추가(지산동)
    ui->comboBox_2->addItem(dong_list[1]);
    ui->comboBox_2->addItem(dong_list[2]);
    */

    // 가로/수평 슬라이더 속성 설정 (체중)
    ui->horizontalSlider->setMinimum(40);
    ui->horizontalSlider->setMaximum(100);

    // 세로/수직 슬라이더 속성 설정 (키)
    ui->verticalSlider->setMinimum(100);
    ui->verticalSlider->setMaximum(230);

    // 가로/수평 스크롤바 속성 설정 (경력)
    ui->horizontalScrollBar->setMinimum(1);
    ui->horizontalScrollBar->setMaximum(9);

    // 세로/수직 스크롤바 속성 설정 (희망연봉)
    ui->verticalScrollBar->setMinimum(3000);
    ui->verticalScrollBar->setMaximum(7000);
    // 최소/최대값 뒤집기 (현프로젝트에서는 사용하지않음)
    //ui->verticalScrollBar->setInvertedAppearance(true);

    // 라인에디터 읽기 전용 속성 설정
    ui->lineEdit_7->setReadOnly(true);
    ui->lineEdit_8->setReadOnly(true);
    ui->lineEdit_9->setReadOnly(true);
    ui->lineEdit_10->setReadOnly(true);

    // 다이얼 위젯 속성 설정
    ui->dial->setMinimum(0);
    ui->dial->setMaximum(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 남자버튼
void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);               // 남자 버튼 비활성화
    ui->pushButton_2->setEnabled(true);             // 여자 버튼 활성화
    ui->pushButton_3->setEnabled(true);             // 기타 버튼 활성화
    ui->label_13->setText(ui->pushButton->text());  // 남자 텍스트 라벨에 입력
}

// 여자버튼
void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(true);
    ui->label_13->setText(ui->pushButton_2->text());
}

// 기타버튼
void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
    ui->label_13->setText(ui->pushButton_3->text());
}

// 계산버튼
void MainWindow::on_pushButton_4_clicked()
{
    int korean, english, math, average;

    korean = ui->lineEdit_2->text().toInt();             // 국어 점수 가져오기
    english = ui->lineEdit_3->text().toInt();            // 영어 점수 가져오기
    math = ui->lineEdit_4->text().toInt();              // 수학 점수 가져오기
    average = (korean + english + math) / 3;         // 평균 점수 계산

    ui->label_8->setText(ui->lineEdit->text());         // 이름 가져와서 보여주기
    ui->label_24->setText(QString::number(average)); // 평균 점수 보여주기
}

// 리셋버튼
void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");

    ui->label_8->setText("");
    ui->label_24->setText("");
}

// 선택완료버튼
void MainWindow::on_pushButton_6_clicked()
{
    QString age = "", hobby = "";       // 문자열 변수 age, hobby 생성 및 초기화

    if(ui->radioButton->isChecked())    // 20대 라디오버튼 체크확인
        age = ui->radioButton->text();  // age 변수에 20대 텍스트 넣기
    if(ui->radioButton_2->isChecked())
        age = ui->radioButton_2->text();
    if(ui->radioButton_3->isChecked())
        age = ui->radioButton_3->text();

    if(ui->checkBox->isChecked())
        hobby = hobby + ui->checkBox->text(); // hobby 변수에 항목 추가
    if(ui->checkBox_2->isChecked())
        hobby = hobby + ui->checkBox_2->text();
    if(ui->checkBox_3->isChecked())
        hobby = hobby + ui->checkBox_3->text();

    ui->lineEdit_11->setText(age + "," + hobby);    // 결과에 나이, 취미 보여주기
}

// 리셋버튼
void MainWindow::on_pushButton_7_clicked()
{
    // 같은 부모를 둔 라디오 버튼들은 한시점에 항상 하나의 버튼만 on 상태로 유지되는 속이 있음 (AutoExclusive)

    ui->radioButton->setAutoExclusive(false);   // 원버튼유지 속성 해제
    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton_3->setAutoExclusive(false);

    ui->radioButton->setChecked(false);         // 라디오버튼 체크 해제
    ui->radioButton_2->setChecked(false);
    ui->radioButton_3->setChecked(false);

    ui->radioButton->setAutoExclusive(true);    // 원버튼유지 속성 부여
    ui->radioButton_2->setAutoExclusive(true);
    ui->radioButton_3->setAutoExclusive(true);

    ui->checkBox->setChecked(false);            // 체크박스 체크 해제
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);

    ui->lineEdit_11->setText("");                   //  결과 초기화
}

 // 리스트항목 클릭시 발생 이벤트 함수
void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    // 리스트 아이템 클릭시, 클릭된 아이템 텍스트 입력란에 채우기
    ui->lineEdit_5->setText(item->text());
}

// 구 콤보박스
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->comboBox_2->clear();

    switch (index) {
    case 0 : // 구 콤보박스가 동구일때
        ui->comboBox_2->addItem(dong_list[0]);
        ui->comboBox_2->addItem(dong_list[1]);
        ui->comboBox_2->addItem(dong_list[2]);
        break;
    case 1 : // 구 콤보박스가 서구일때
        ui->comboBox_2->addItem(dong_list[3]);
        ui->comboBox_2->addItem(dong_list[4]);
        ui->comboBox_2->addItem(dong_list[5]);
        break;
    case 2 : // 구 콤보박스가 남구일때
        ui->comboBox_2->addItem(dong_list[6]);
        ui->comboBox_2->addItem(dong_list[7]);
        ui->comboBox_2->addItem(dong_list[8]);
        break;
    case 3 : // 구 콤보박스가 북구일때
        ui->comboBox_2->addItem(dong_list[9]);
        ui->comboBox_2->addItem(dong_list[10]);
        ui->comboBox_2->addItem(dong_list[11]);
        break;
    }
}

// 동 콤보박스
void MainWindow::on_comboBox_2_currentIndexChanged()
{
    QString gu, dong;
    gu = ui->comboBox->currentText();
    dong = ui->comboBox_2->currentText();
    ui->lineEdit_6->setText(gu + " " + dong);
}

// 가로/수평 슬라이더 값 변경시 함수 (체중)
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->lineEdit_7->setText(QString::number(value));
}

// 가로/수평 스크롤바 값 변경시 함수 (경력)
void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    ui->lineEdit_8->setText(QString::number(value));
}

// 세로/수직 슬라이더 값 변경시 함수 (키)
void MainWindow::on_verticalSlider_valueChanged(int value)
{
    ui->lineEdit_9->setText(QString::number(value));
}

// 세로/수직 스크롤바 값 변경시 함수 (희망연봉)
void MainWindow::on_verticalScrollBar_valueChanged(int value)
{
    ui->lineEdit_10->setText(QString::number(value));
}

// 다이얼 값 변경시 함수
void MainWindow::on_dial_valueChanged(int value)
{
    ui->label_20->setText(QString::number(value));
}

// 종료버튼
void MainWindow::on_pushButton_10_clicked()
{
    this->close(); // 현재 인스턴스 종료
}
