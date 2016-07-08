#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include "ckdbengine.h" //DB 관리를 위한 엔진을 include한다.
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QListView>
#include <QSplitter>
#include <QPushButton>
#include <QDialogButtonBox>

class MainForm : public QWidget
{
    Q_OBJECT

public:
    MainForm(QWidget *parent = 0);
    ~MainForm();

private slots:
    //데이터 표시 함수
    void updateCategoryLevel2ListView();
    void updateCategoryLevel3ListView();
    void updateContentPanel();


    //데이터 조작용 함수(Category 패널)
    void insertCategory();
    void addCategory();
    void deleteCategory();
    void confirmCategory();

    //데이터 조작용 함수(Content 패널)
    void insertContent();
    void addContent();
    void deleteContent();
    void confirmContent();

private:
    //화면 구성요소 생성 함수
    void createCategoryPanel();
    void createContentPanel();

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
            QTextEdit *bodyTextEdit;
            //조작버튼들(Content 패널용)
            QDialogButtonBox *contentDialogButtonBox;
                QPushButton *insertContentButton;
                QPushButton *addContentButton;
                QPushButton *deleteContentButton;
                QPushButton *confirmContentButton;


    //전체 레이아웃을 잡아줄 스플리터
    QSplitter *mainSplitter;

    //향후 추가작업을 대비해 스플리터를 다시 감쌌음
    QVBoxLayout *mainLayout;
};

#endif // MAINFORM_H
