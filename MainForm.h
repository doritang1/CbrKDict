#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSplitter>

class MainForm : public QWidget
{
    Q_OBJECT

public:
    MainForm(QWidget *parent = 0);
    ~MainForm();

private:
    void createTitlePanel();
    void createContentPanel();

    QWidget *TitlePanel;
    QVBoxLayout *TitlePanelLayout;
    QLabel *TitleIdLabel;
    QLineEdit *TitleIdLineEdit;
    QLabel *TitleLabel;
    QLineEdit *TitleLineEdit;

    QWidget *ContentPanel;
    QVBoxLayout *ContentPanelLayout;
    QLabel *ContentIdLabel;
    QLineEdit *ContentIdLineEdit;
    QLabel *ContentLabel;
    QLineEdit *ContentLineEdit;

    QSplitter *MainSplitter;
    QVBoxLayout *MainLayout;
};

#endif // MAINFORM_H
