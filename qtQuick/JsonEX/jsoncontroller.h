#ifndef JSONCONTROLLER_H
#define JSONCONTROLLER_H

#include <QFile>

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

class JsonController : public QObject
{
    Q_OBJECT

    static const QString kFileExam;

public:
    JsonController();
    ~JsonController() {};

public:
    Q_INVOKABLE void modify(const QByteArray &info);
    Q_INVOKABLE void make();    // 파일이 없으면 생성
    Q_INVOKABLE void read();    // 파일을 읽어 멤버변수에 값 대입
    Q_INVOKABLE void write();
    Q_INVOKABLE void open(const int idx, const bool is_write = false);

/* json내부를 편집할 때 사용할 변수들 */
private:
    QJsonObject title_;         // body1 과 body2 를 보유한 변수
    QJsonObject body1_;       // tree1 을 보유
    QJsonObject body2_;       // tree2_1 과 tree2_2 를 보유
    QJsonDocument doc_;     // Write 용도 :  QJsonObject 들이 담을 내용을 QJsonDocument 를 통해 획득 == json 파일 내용과 동일
    QFile file_;
};

#endif // JSONCONTROLLERR_H
