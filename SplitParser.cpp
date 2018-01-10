#include "SplitParser.h"

SplitParser::SplitParser(QObject *parent) : QObject(parent)
{

}

void SplitParser::splitHtml(const QString &text, int &counterWord)
{

    reader.clear();
    reader.addData(text);

    //특수문자 처리를 위한 EntityResolver를 지정해준다.
    if (htmlNamedEntityResolver == NULL) {
        htmlNamedEntityResolver = new HtmlNamedEntityResolver();
    }
    reader.setEntityResolver(htmlNamedEntityResolver);

    //분석 시작
    reader.readNext();
    while(!reader.atEnd()){
        if(reader.isStartElement()){
            if(reader.name() == "html"){
                readHtmlElement(reader, counterWord);
            }
        }else{
            reader.readNext();
        }//if(reader.isStartElement())
    }//while(!reader.atEnd()

    //에러문 출력
    if(reader.hasError()){
//        QMessageBox::information(this, "Error!!!",
//                                 QString("%1\nLine: %2\nColumn: %3\nCharacter at: %4\nToken: %5\nHtml: ...%6...")
//                                        .arg(reader.errorString())
//                                        .arg(reader.lineNumber())
//                                        .arg(reader.columnNumber())
//                                        .arg(reader.characterOffset())
//                                        .arg(reader.tokenString())
//                                        .arg(text.mid(reader.characterOffset()-10, 20)),
//                                 "OK");
        int s = text.indexOf("<title>");
        int e = text.indexOf("</title>");
        QString str = text.mid(s + 7, e-(s+7));
        emit sendError(QString("Title: %1\nError: %2\nPart: %3\n")
                       .arg(str)
                       .arg(reader.errorString())
                       .arg(text.mid(reader.characterOffset()-30, 40)));
    }//if(reader.hasError())
}

//6-1:<html>태그 내부를 읽는다.
void SplitParser::readHtmlElement(QXmlStreamReader &reader, int &counterWord)
{
    reader.readNext();
    while(!reader.atEnd()){
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }//if (reader.isEndElement())

        if(reader.isStartElement()){
            if(reader.name() == "head"){
                readHeadElement(reader, counterWord);
            }else if(reader.name() == "body"){
                readBodyElement(reader, counterWord);
            }else{
                skipUnknownElement(reader);
            }//if(reader.name() == "head"
        }else{
            reader.readNext();
        }//if(reader.isStartElement())
    }//while(!reader.atEnd())
}

//6-2:<head>태그 내부를 읽는다.
void SplitParser::readHeadElement(QXmlStreamReader &reader, int &counterWord)
{
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }//if (reader.isEndElement())

        if (reader.isStartElement()) {
            if (reader.name() == "title") {
                readTitleElement(reader, counterWord);
            } else {
                skipUnknownElement(reader);
            }
        } else {
            reader.readNext();
        }//if (reader.isStartElement())
    }//while (!reader.atEnd())
}

//6-3<title>태그를 읽는다.
void SplitParser::readTitleElement(QXmlStreamReader &reader, int &counterWord)
{
    //readElementText()가 불려진 이후에는 EndElement로 이동하므로
    //isEndElement 조건식 이전에 readElementText()가 불려져야 한다.
    QString title = reader.readElementText();
    if(title.length()>0){ //빈문자열("")은 건너뛴다.
        emit sendTitle(title, counterWord);
    }

    if (reader.isEndElement()){
        reader.readNext();
    }
}

//6-4: <body>태그를 읽는다.
void SplitParser::readBodyElement(QXmlStreamReader &reader, int &counterWord)
{
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }//if (reader.isEndElement())

        if (reader.isStartElement()) {
            if (reader.name() == "p") {
                readPElement(reader, counterWord);
            } else {
                skipUnknownElement(reader);
            }//if (reader.name() == "p")
        } else {
            reader.readNext();
        }//if (reader.isStartElement())
    }
}

////6-5: <p>태그를 읽는다.
void SplitParser::readPElement(QXmlStreamReader &reader, int &counterWord)
{
    QString pStr;

    reader.readNext();
    while(!reader.atEnd()){
        if(reader.tokenType() == QXmlStreamReader::Characters){
            //글자들을 읽어나가다가(단, <와 >는 &lt;와 &gt;로 남겨둠)
            pStr += reader.text().toString().toHtmlEscaped();
        }else if(reader.isStartElement()){
            if(reader.name() == "p"){ // startelement을 만나고 그것이 <p>면
                reader.readNext();
                continue;
            }else if(reader.name() == "font"){ // startelement을 만나고 그것이 <font>면
                reader.readNextStartElement();
                continue;
            }else{ // startElement을 만나고 그것이 <span> 또는 <u>,<sup>이면
                // "class" attribute를 가지고 있으면 그대로 표시하고
                if(reader.attributes().hasAttribute("class")){
                    pStr += "<" + reader.name().toString()
                            + " class=\""
                            + reader.attributes().value("class").toString()
                            + "\">"; //태그를 그대로 붙여준다.
                }else{
                    //"class" attribute가 없으면 태그만 그대로 붙여준다.
                    pStr += "<" + reader.name().toString() + ">";
                }
            }//if(reader.name() == ?)
        }else if(reader.isEndElement()){ //endelement도 마찬가지다.
            if(reader.name() == "p" || reader.name() == "font" || reader.name() == "body" || reader.name() == "html"){
                reader.readNext();
                continue;
            }else{
                pStr += "</"+ reader.name().toString() + ">";
            }//if(reader.name() == ?)
        }//else if(reader.isEndElement())
        reader.readNext();
    }//while(!reader.atEnd())

    //<b>태그로 감싸진 타이틀을 추출하여,
    QString titleUml;
    int beginTitlePos = 0;
    int endTitlePos = 0;
    while(1){
        beginTitlePos = pStr.indexOf("<b>", beginTitlePos);
        if(beginTitlePos < 0) break;
        endTitlePos = pStr.indexOf("</b>", beginTitlePos);
        titleUml += pStr.mid(beginTitlePos, endTitlePos-beginTitlePos).remove(QRegExp("<[^>]*>"));
        titleUml = titleUml.remove("|").remove(".");
        beginTitlePos = endTitlePos;
    }

    //umlaut의 종류를 나열한 후
    QStringList uml;
    uml<<"Ä"<<"Ö"<<"Ü"<<"ä"<<"ö"<<"ü"<<"ß";
    QStringListIterator itor(uml);

    //나열된 umlaut를 가지고 있는지 검사하여 가지고 있으면 타이틀로 뽑아낸다.
    while(itor.hasNext()){
        if(titleUml.contains(itor.next().toUtf8().constData())){
            emit sendTitle(titleUml, counterWord);
            break;
        }
    }//while(itor.hasNext())

    //전체 body문을 출력한다.
    emit sendBody(counterWord, pStr.trimmed());

// 태그를 무시하고 내용만 읽어내는 코드
//    plainTextEditDefinition->appendPlainText(reader.readElementText(QXmlStreamReader::IncludeChildElements));
//    if (reader.isEndElement()){
//        reader.readNext();
//    }
}

//6-6: 알려지지 않은 태그는 건너뛴다.
void SplitParser::skipUnknownElement(QXmlStreamReader &reader)
{
    reader.readNext();
    while (!reader.atEnd()) {
        if (reader.isEndElement()) {
            reader.readNext();
            break;
        }

        if (reader.isStartElement()) {
            skipUnknownElement(reader);
        } else {
            reader.readNext();
        }
    }
}
