#ifndef SPLITPARSER_H
#define SPLITPARSER_H

#include <QObject>
#include <QtXml>
#include <htmlnamedentityresolver.h>

class SplitParser : public QObject
{
    Q_OBJECT
public:
    explicit SplitParser(QObject *parent = nullptr);
    HtmlNamedEntityResolver *htmlNamedEntityResolver = NULL;
    void splitHtml(const QString &, int &);
private:

    QXmlStreamReader reader;
    void readHtmlElement(QXmlStreamReader &, int &);
    void readHeadElement(QXmlStreamReader &, int &);
    void readTitleElement(QXmlStreamReader &, int &);
    void readBodyElement(QXmlStreamReader &, int &);
    void readPElement(QXmlStreamReader &, int &);
    void skipUnknownElement(QXmlStreamReader &);

signals:
    void sendTitle(QString, int);
    void sendBody(int, QString);
    void sendError(QString);
public slots:
};

#endif // SPLITPARSER_H
