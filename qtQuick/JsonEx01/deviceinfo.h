#ifndef DEVICEINFO_H
#define DEVICEINFO_H

#include <QJsonObject>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QByteArray>


class Deviceinfo : public QObject
{
    Q_OBJECT

public:
    Deviceinfo();

    QJsonObject jsonObj;

    QString getDevName() const;
    void setDevName(const QString &value);

    QString getDevID() const;
    void setDevID(const QString &value);

    bool saveJSON();
    bool loadJSON();

    void showDevInfo();

private:
    QString devName;
    QString devID;

};

#endif // DEVICEINFO_H
