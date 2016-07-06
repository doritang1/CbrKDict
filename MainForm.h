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
    QVBoxLayout *titlePanelLayout;
    QGridLayout *titleGridLayout;
    QLabel *titleidLabel;
    QLineEdit *titleidLineEdit;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QListView *titleListView;

    QFrame *contentPanel;
    QVBoxLayout *contentPanelLayout;
    QHBoxLayout *contentidLayout;
    QLabel *contentidLabel;
    QLineEdit *contentidLineEdit;
    QTextEdit *contentTextEdit;

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
