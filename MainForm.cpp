#include "MainForm.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
{
    createTitlePanel();
    createContentPanel();

    MainSplitter = new QSplitter(Qt::Vertical);
    MainSplitter->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    MainSplitter->addWidget(TitlePanel);
    MainSplitter->addWidget(ContentPanel);
    MainLayout = new QVBoxLayout;
    MainLayout->addWidget(MainSplitter);

    setLayout(MainLayout);
}

MainForm::~MainForm()
{

}

void MainForm::createTitlePanel()
{
    TitlePanel = new QFrame;
    TitlePanel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    TitleIdLabel = new QLabel(tr("Title ID"));
    TitleIdLineEdit = new QLineEdit();
    TitleLabel = new QLabel(tr("Title"));
    TitleLineEdit = new QLineEdit();

    TitlePanelLayout = new QVBoxLayout;
    TitlePanelLayout->addWidget(TitleIdLabel);
    TitlePanelLayout->addWidget(TitleIdLineEdit);
    TitlePanelLayout->addWidget(TitleLabel);
    TitlePanelLayout->addWidget(TitleLineEdit);
    TitlePanel->setLayout(TitlePanelLayout);
}

void MainForm::createContentPanel()
{
    ContentPanel = new QFrame;
    ContentPanel->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    ContentIdLabel = new QLabel(tr("Content ID"));
    ContentIdLineEdit = new QLineEdit();
    ContentLabel = new QLabel(tr("Content"));
    ContentLineEdit = new QLineEdit();
    ContentPanelLayout = new QVBoxLayout;
    ContentPanelLayout->addWidget(ContentIdLabel);
    ContentPanelLayout->addWidget(ContentIdLineEdit);
    ContentPanelLayout->addWidget(ContentLabel);
    ContentPanelLayout->addWidget(ContentLineEdit);
    ContentPanel->setLayout(ContentPanelLayout);
}
