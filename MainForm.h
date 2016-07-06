#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
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
    //    void insertTitle();
    //    void addTitle();
    //    void deleteTitle();
    //    void confirmTitle();

    //    void insertTitle();
    //    void addTitle();
    //    void deleteTitle();
    //    void confirmTitle();
private:
    void createTitlePanel();
    void createContentPanel();

    QFrame *titlePanel;
    QFrame *titleViewPanel;
    QHBoxLayout *titleidLayout;
    QHBoxLayout *titleLayout;
    QVBoxLayout *viewVBoxLayout;
    QVBoxLayout *titlePanelLayout;
    QLabel *titleidLabel;
    QLineEdit *titleidLineEdit;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QListView *titleListView;
    QSpacerItem *titleSpacer;

    QFrame *contentPanel;
    QHBoxLayout *contentidLayout;
    QHBoxLayout *contentLayout;
    QVBoxLayout *contentPanelLayout;
    QLabel *contentidLabel;
    QLineEdit *contentidLineEdit;
    QTextEdit *contentTextEdit;
    QSpacerItem *contentSpacer;

    QSplitter *mainSplitter;

    QPushButton *insertTitleButton;
    QPushButton *addTitleButton;
    QPushButton *deleteTitleButton;
    QPushButton *confirmTitleButton;
    QDialogButtonBox *titleDialogButtonBox;

    QPushButton *insertContentButton;
    QPushButton *addContentButton;
    QPushButton *deleteContentButton;
    QPushButton *confirmContentButton;
    QDialogButtonBox *contentDialogButtonBox;

    QVBoxLayout *mainLayout;
};

#endif // MAINFORM_H
