#include "jsoncontroller.h"

void JsonController::open(const int idx, const bool is_write)
{
    if (idx == 0)                           // idx = 파일경로
        file_.setFileName(kFileExam);
    else { }
        // something...

    /* is_write : 파일 읽기와 갱신 구분 */
    is_write == true ?
        file_.open(QIODevice::ReadWrite | QIODevice::Truncate)      // Truncate 옵션 : 기존 내용 지우기
        : file_.open(QIODevice::ReadWrite);

    /* JSON 내용을 모두 읽어 JSON Doc 형태로 변환 */
    QByteArray load_data = file_.readAll();             // json 내부의 항목들을 읽어 QByteArray 형태로 저장
    doc_ = QJsonDocument::fromJson(load_data);      // load_data 에 저장한 데이터들을 json 형태로 변환하여 QJsonObject 변수인 doc_ 로 전달
}


const QString JsonController::kFileExam = "exam.json";

/* 생성자 */
JsonController::JsonController()
{
    if (QFile::exists(kFileExam) == false)  // exists() 함수를 이용해 json 파일의 유무 확인
        make();                           // 없으면 생성
    read();
}

void JsonController::make()
{
    open(0);    // 0 전달 : 파일을 Read/Write 모드로 읽어옴

    // Tree Depth 2 - 세부내용
    body1_["tree1"] = "null";

    body2_["tree2_1"] = "null";
    body2_["tree2_2"] = "null";

    // Tree Depth 1 - 제목
    title_["body1"] = body1_;
    title_["body2"] = body2_;

    write();
}

void JsonController::write()
{
    /* JSON 파일에 쓰기 */
    doc_.setObject(title_);
    file_.write(doc_.toJson());
    file_.close();
}

void JsonController::read()
{
    open(0);

    // 파일의 내용을 읽어 변수에 대입
    body1_ = doc_.object()["body1"].toObject();
    body2_ = doc_.object()["body2"].toObject();

    file_.close();
}

void JsonController::modify(const QByteArray &info)
{
    open(0, true);

    body1_["tree1"] = "firest" ;

    body2_["tree2_1"] = "2_1" ;
    body2_["tree2_2"] = "2_2" ;

    // Tree Depth 1 - 제목
    title_["body1"] = body1_ ;
    title_["body2"] = body2_ ;

    write();
}
