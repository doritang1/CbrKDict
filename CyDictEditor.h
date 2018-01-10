#ifndef CYDICTEDITOR_H
#define CYDICTEDITOR_H

#include <QDialog>
#include <QDir>
#include <QStringListModel>
#include <QMultiMap>
#include <QMap>
#include "ui_CyDictEditor.h"
#include <stdint.h>
#include <QProgressDialog>
<<<<<<< HEAD
=======

>>>>>>> e9210c6c87dcc155fa15d2179bd5fd64809c5b95
#include <QtConcurrent>
#include <QFutureWatcher> //progressbar를 비동기적으로 사용

namespace Ui {
class CyDictEditor;
}

//파일포인터를 저장하기 위한 구조체
struct _position
{
    uint32_t contentBegin;
    uint32_t contentLength;
};

class CyDictEditor : public QDialog, public Ui::CyDictEditor
{
    Q_OBJECT

public:
    explicit CyDictEditor(QWidget *parent = 0);

private slots:
    void on_toolButtonFileSelect_clicked();
    void on_pushButtonSplit_clicked();
    void on_pushButtonValidate_clicked();
    void on_pushButtonMerge_clicked();
    void on_pushButtonSave_clicked();
    void on_listViewFiles_clicked(const QModelIndex &index);
    void on_listViewWordFromMap_clicked(const QModelIndex &index);
    void on_pushButtonCreateDict_clicked();
    void on_listViewWordFromFile_clicked(const QModelIndex &index);

    void on_pushButton_clicked();
    void showTitles();

    void receiveTitle(QString, int);
    void receiveBody(int, QString);
    void receiveError(QString);

private:
    Ui::CyDictEditor *ui;
    QDir dirSource;
    QStringList *listSources;
    QString *stringHtml;
    QString *str;
    QStringListModel *modelFiles;
    QStringListModel *modelTitles;
    QStringListModel *modelWords;
    QStringList *strlstHtmls;

    //파일에 저장하기 전에 임시로 쓰는 자료구조
    QMultiMap<QString, int> mltmapTitles;
    QMap<int, QString> mapDefinitions;
    //파일에 저장된 타이틀을 불러올 때 쓰는 자료구조
    QMultiMap<QString, _position> mltmapWords;
    QString strFileName;

    bool validateHtml(QString *);
<<<<<<< HEAD
=======

    void splitHtml(QString);
>>>>>>> e9210c6c87dcc155fa15d2179bd5fd64809c5b95

    void createDict(QString &dictionaryName);
    void loadDict(QString &strFilePath);
    void loadDictD(QString &strFilePath);

};

#endif // CYDICTEDITOR_H
