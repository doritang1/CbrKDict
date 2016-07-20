#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include "ckdbengine.h" //DB 관리를 위한 엔진을 include한다.
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QListView>
#include <QTableView>
#include <QSplitter>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QPrintPreviewDialog>
#include "qtrpt.h"
#include <QtWebKitWidgets/QWebView>

class MainForm : public QWidget
{
    Q_OBJECT

public:
    MainForm(QWidget *parent = 0);
    ~MainForm();
protected:
    //키입력을 감시해서 다른 행동을 하게 하기 위한 일종의 후킹함수
   bool eventFilter(QObject* obj, QEvent* event);
private slots:
    //데이터 표시 함수
    void updateCategoryLevel2ListView();
    void updateCategoryLevel3ListView();
    void updateContentPanel();

    //포커스를 주고 받은 컨트롤을 처리하는 함수(어떤 위젯에 대해서 삽입,삭제 등을 처리할 것인지 판단)
    void focusChanged(QWidget *from, QWidget *to);

    //데이터 조작용 함수(Category 패널)
    void insertCategory();
    void addCategory();
    void deleteCategory();
    void confirmCategory();

    //데이터 조작용 함수(Content 패널)
    void addContent();
    void deleteContent();
    void confirmContent();
    void currentContent();
    void printBody(); //현재 내용을 출력
    void slotPrint(QPrinter *);//printBody()에서 다시 호출
    void printReport(); //리포트 생성
    //리포트에 데이터 연결
    void setValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage);

private:
    //화면 구성요소 생성 함수
    void createCategoryPanel();
    void createContentPanel();

    //현재 포커스를 받은 컨트롤의 색인을 저장하는 변수
    int focusedWidget;

    //데이터베이스 엔진 선언
    CKDBEngine *sqlDb;

    //Category 패널에 포함되는 요소들
    QFrame *categoryPanel;
        QVBoxLayout *categoryPanelLayout;
            //데이터 표시 요소들
            QGridLayout *categoryGridLayout;
                QLabel *categoryLevel1Label;
                QListView *categoryLevel1ListView;
                QLabel *categoryLevel2Label;
                QListView *categoryLevel2ListView;
                QLabel *categoryLevel3Label;
                QListView *categoryLevel3ListView;
            //조작버튼들(Category 패널용)
            QDialogButtonBox *categoryDialogButtonBox;
                QPushButton *insertCategoryButton;
                QPushButton *addCategoryButton;
                QPushButton *deleteCategoryButton;
                QPushButton *confirmCategoryButton;

    //Content 패널에 포함되는 요소들
    QFrame *contentPanel;
        QVBoxLayout *contentPanelLayout;
            //데이터 표시 요소들
            QHBoxLayout *titleHBoxLayout;
                QFormLayout *titleFormLayout;
                    QLabel *titleLabel;
                    QLineEdit *titleLineEdit;
                QPushButton *titleSearchPushButton;
            //QPlainTextEdit *bodyTextEdit;
            QWebView *bodyWebView;
            QTableView *contentTableView;
            //조작버튼들(Content 패널용)
            QDialogButtonBox *contentDialogButtonBox;
                QPushButton *addContentButton;
                QPushButton *deleteContentButton;
                QPushButton *confirmContentButton;
                QPushButton *printBodyButton;
                QPushButton *printReportButton;


    //전체 레이아웃을 잡아줄 스플리터
    QSplitter *mainSplitter;

    //향후 추가작업을 대비해 스플리터를 다시 감쌌음
    QVBoxLayout *mainLayout;

    //인쇄관련
    QtRPT *reportDocument;

    //기타
    QPrinter *prntDevice;
    QPrintPreviewDialog *prntPreviewDialog;
};

#endif // MAINFORM_H
