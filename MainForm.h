#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSplitter>
#include <QSplitterHandle>

class MainForm : public QWidget
{
    Q_OBJECT

public:
    MainForm(QWidget *parent = 0);
    ~MainForm();

private:
    void createTitlePanel();
    void createContentPanel();

    QFrame *TitlePanel;
    QVBoxLayout *TitlePanelLayout;
    QLabel *TitleIdLabel;
    QLineEdit *TitleIdLineEdit;
    QLabel *TitleLabel;
    QLineEdit *TitleLineEdit;

    QFrame *ContentPanel;
    QVBoxLayout *ContentPanelLayout;
    QLabel *ContentIdLabel;
    QLineEdit *ContentIdLineEdit;
    QLabel *ContentLabel;
    QLineEdit *ContentLineEdit;

    QSplitter *MainSplitter;
    QSplitterHandle *handle;
    QVBoxLayout *MainLayout;
};

#endif // MAINFORM_H
