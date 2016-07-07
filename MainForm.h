#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include "ckdbengine.h" //DB 관리를 위한 엔진을 include한다.
#include <QVBoxLayout>
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
    void updateCategoryLevel2ListView();
    void updateCategoryLevel3ListView();
    //    void insertTitle();
    //    void addTitle();
    //    void deleteTitle();
    //    void confirmTitle();

    //    void insertTitle();
    //    void addTitle();
    //    void deleteTitle();
    //    void confirmTitle();
private:
    void createCategoryPanel();
    void createContentPanel();

    CKDBEngine *sqlDb;

    QFrame *categoryPanel;
    QVBoxLayout *categoryPanelLayout;
    QGridLayout *categoryGridLayout;
    QLabel *categoryLevel1Label;
    QListView *categoryLevel1ListView;
    QLabel *categoryLevel2Label;
    QListView *categoryLevel2ListView;
    QLabel *categoryLevel3Label;
    QListView *categoryLevel3ListView;

    QFrame *contentPanel;
    QVBoxLayout *contentPanelLayout;
    QLabel *titleidLabel;
    QLineEdit *titleidLineEdit;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QPushButton *titleSearchPushButton;
    QTextEdit *bodyTextEdit;

    QSplitter *mainSplitter;

    QPushButton *insertCategoryButton;
    QPushButton *addCategoryButton;
    QPushButton *deleteCategoryButton;
    QPushButton *confirmCategoryButton;
    QDialogButtonBox *categoryDialogButtonBox;

    QPushButton *insertContentButton;
    QPushButton *addContentButton;
    QPushButton *deleteContentButton;
    QPushButton *confirmContentButton;
    QDialogButtonBox *contentDialogButtonBox;

    QVBoxLayout *mainLayout;
};

#endif // MAINFORM_H
