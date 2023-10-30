#include <QtCore>
#include <QQuickTextDocument>
#include <QtGui/QTextCharFormat>
#include <QtCore/QTextCodec>

class DocumentHandler : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    //Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    DocumentHandler(QObject *parent = nullptr) : QObject(parent) { };
    ~DocumentHandler() {};

    //Q_INVOKABLE void read();
    //Q_INVOKABLE void write();

    QUrl fileUrl() const { return m_fileUrl; };
    QString text() const { return m_text; };

    QString documentTitle() const { return m_documentTitle;};

public slots:
    void setFileUrl(const QUrl &arg);
    void setText(const QString &arg);
    void saveAs(const QUrl &arg, const QString &fileType);

    void setDocumentTitle(QString arg);

signals:
    void fileUrlChanged();

    void textChanged();
    void documentTitleChanged();
    void error(QString message);

private:
    QTextDocument *m_doc;
    QUrl m_fileUrl;
    QString m_text;
    QString m_documentTitle;
};
