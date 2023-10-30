/*
 * < QJSON 사용법 >
 * 1. json 에 들어갈 내용 개체 생성해주기
 * 2. QJsonObject 생성하기
 * 3. QJsonObject 에 내용 개체 값 삽입
 * 4. QJsonDocument 에 QJsonObject 저장하기
 * 5. QFile 에 QJsonDocument 내용 쓰기
 * 6. Read 함수를 생성하여 QFile (.json) 내용 읽기
 *
 */

#include <QtCore>
#include <iostream>
#include <QIODevice>

using namespace std;

struct Book
{
    string name;
    double price;
    Book( string _name, double _price )
    {
        name = _name;
        price = _price;
    }
};

void CreateJson(const QString &path)
{
    Book obj1( "high school mathematics", 12 );
    QJsonObject book1;
    book1.insert( "name", obj1.name.c_str() );
    book1.insert( "price", obj1.price );

    Book obj2( "advanced high school mathematics", 20 );
    QJsonObject book2;
    book2.insert( "name", obj2.name.c_str() );
    book2.insert( "price", obj2.price );

    QJsonObject content;
    content.insert( "book1", book1 );
    content.insert( "book2", book2 );

    // QJsonDocument 에 QJsonObject 작성성하기
    QJsonDocument document;
    document.setObject( content );
    QByteArray bytes = document.toJson( QJsonDocument::Indented ); // toJson : document에 json작성 , Indented : 작성방식옵션

    // file 에 json 내용입력
    QFile file( path );
    if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
    {
        QTextStream iStream( &file );
        iStream.setCodec( "utf-8" );
        iStream << bytes;
        file.close();
    }
    else
    {
        cout << "file open failed: " << path.toStdString() << endl;
    }
}

void ReadJson(const QString &path)
{
    QFile file( path );
    if( file.open( QIODevice::ReadOnly ) )
    {
        QByteArray bytes = file.readAll();
        file.close();

        QJsonParseError jsonError;
        QJsonDocument document = QJsonDocument::fromJson( bytes, &jsonError );
        if( jsonError.error != QJsonParseError::NoError )
        {
            cout << "fromJson failed: " << jsonError.errorString().toStdString() << endl;
            return ;
        }
        if( document.isObject() )
        {
            QJsonObject jsonObj = document.object();
            QStringList books;
            books << "book1" << "book2";
            for( auto book: books )
            {
                if( jsonObj.contains( book ) )
                {
                    QJsonObject obj = jsonObj.value( book ).toObject();
                    QStringList keys = obj.keys();
                    for( auto key: keys )
                    {
                        auto value = obj.take( key );
                        if( value.isDouble() )
                        {
                            qDebug() << key << " : " << value.toDouble();
                        }
                        else if( value.isString() )
                        {
                            qDebug() << key << " : " << value.toString();
                        }

                    } // for
                } // if
            } // for
        } // if
    }
}

int main(int argc,char **argv)
{
    QString path = "/home/eunyoung/.config/smMission/test.json";
    CreateJson( path );
    ReadJson( path );
    return 0;
}
