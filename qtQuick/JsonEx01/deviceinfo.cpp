#include "deviceinfo.h"

Deviceinfo::Deviceinfo()
{
}

QString Deviceinfo::getDevName() const
{
    return devName;
}

void Deviceinfo::setDevName(const QString &value)
{
    devName = value;
}

QString Deviceinfo::getDevID() const
{
    return devID;
}
void Deviceinfo::setDevID(const QString &value)
{
    devID = value;
}

bool Deviceinfo::saveJSON()
{
    this->jsonObj["devName"] = devName;
    this->jsonObj["devID"] = devID;

    QFile saveFile(QStringLiteral("deviceInfo.json"));      // QStringLiteral(str) : str 에서 데이터 생성

    if(!saveFile.open(QIODevice::WriteOnly)){
        qWarning("Could not open json file to save");
        return false;
    }

    QJsonDocument saveDoc(jsonObj);
    saveFile.write(saveDoc.toJson());
    showDevInfo();

    return true;
}

bool Deviceinfo::loadJSON()
{
    QFile loadFile(QStringLiteral("deviceInfo.json"));

    if(!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Could not open json file to read");
        return false;
    }

    QByteArray loadData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));
    jsonObj = loadDoc.object();
    devName = jsonObj["devName"].toString();
    devID = jsonObj["devID"].toString();
    showDevInfo();

    return true;
}

void Deviceinfo::showDevInfo()
{
    qDebug() << ":: Device Name : " << devName;
    qDebug() << ":: Device ID : " << devID;
    qDebug() << ":: jsonObj[\"devName\"] = " << jsonObj["devName"].toString();
    qDebug() << ":: jsonObj[\"devID\"] =" << jsonObj["devID"].toString();
}
