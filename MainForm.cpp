#include "MainForm.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
{
    //화면에 표시할 요소들을 담은 패널(프레임)을 생성한다.
    createTitlePanel();
    createContentPanel();

    //스플리터를 생성한다.
    mainSplitter = new QSplitter(Qt::Horizontal);
    mainSplitter->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    mainSplitter->setChildrenCollapsible(false); //스플리터 내부의 요소들이 사라지지 않도록 최소크기를 유지함

    //스플리터에 패널들을 붙인다.
    mainSplitter->addWidget(titlePanel);
    mainSplitter->addWidget(contentPanel);
    //스플리터 내부의 인덱스가 1(두번째)인 컨트롤만 늘어남
    //두번째 인자는 다른 인덱스(예를 들어 첫번째)의 컨트롤 대비 늘어나는 비율, 0이면 안늘어남
    mainSplitter->setStretchFactor(1,1);
    //레이아웃을 생성하여 스플리터를 붙인다.
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(mainSplitter);

    setLayout(mainLayout);
}

MainForm::~MainForm()
{

}

//Title을 표시할 패널을 생성한다.
void MainForm::createTitlePanel()
{
    //프레임을 생성한다.
    titlePanel = new QFrame;
    titlePanel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    /*프레임 안에 나타낼 각종 요소를 생성한다.*/

    //타이틀번호를 나타낼 요소를 생성
    titleidLabel = new QLabel(tr("Title ID"));
    titleidLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    titleidLineEdit = new QLineEdit;
    titleidLineEdit->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    //타이틀을 나타낼 요소를 생성
    titleLabel = new QLabel(tr("Title"));
    titleLineEdit = new QLineEdit;

    //데이터를 표시할 리스트뷰를 생성
    titleListView = new QListView;
    //titleListView->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);





    //그리드 레이아웃 생성후 컨트롤들 추가
    titleGridLayout = new QGridLayout;
    titleGridLayout->addWidget(titleidLabel,0,0);
    titleGridLayout->addWidget(titleidLineEdit,0,1);
    titleGridLayout->addWidget(titleLabel,1,0);
    titleGridLayout->addWidget(titleLineEdit,1,1,1,2);
    titleGridLayout->addWidget(titleListView,2,0,6,3);

    //조작버튼부를 생성
    insertTitleButton = new QPushButton(tr("Insert"));
    addTitleButton = new QPushButton(tr("Add"));
    deleteTitleButton = new QPushButton(tr("Delete"));
    confirmTitleButton = new QPushButton(tr("Confirm"));

    //조작버튼부를 그룹화
    titleDialogButtonBox = new QDialogButtonBox;
    titleDialogButtonBox->addButton(insertTitleButton, QDialogButtonBox::ActionRole);
    titleDialogButtonBox->addButton(addTitleButton, QDialogButtonBox::ActionRole);
    titleDialogButtonBox->addButton(deleteTitleButton, QDialogButtonBox::ActionRole);
    titleDialogButtonBox->addButton(confirmTitleButton, QDialogButtonBox::ActionRole);

//    connect(insertTitleButton, SIGNAL(clicked()), this, SLOT(insertTitle()));
//    connect(addTitleButton, SIGNAL(clicked()), this, SLOT(addTitle()));
//    connect(deleteTitleButton, SIGNAL(clicked()), this, SLOT(deleteTitle()));
//    connect(confirmTitleButton, SIGNAL(clicked()), this, SLOT(confirmTitle()));

    //생성된 요소를 레이아웃에 담는다.
    titlePanelLayout = new QVBoxLayout;
    titlePanelLayout->addLayout(titleGridLayout);
//    titlePanelLayout->addStretch();//스페이서를 추가
    titlePanelLayout->addWidget(titleDialogButtonBox);

    //레이아웃을 프레임에 붙인다.
    titlePanel->setLayout(titlePanelLayout);
}

//Content를 표시할 패널을 생성한다.
void MainForm::createContentPanel()
{
    //프레임을 생성한다.
    contentPanel = new QFrame;
    contentPanel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    //프레임 안에 나타낼 각종 요소를 생성한다.
    contentidLabel = new QLabel(tr("Content ID"));
    contentidLabel->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    contentidLineEdit = new QLineEdit();
    contentidLineEdit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    contentidLayout = new QHBoxLayout;
    contentidLayout->addWidget(contentidLabel);
    contentidLayout->addWidget(contentidLineEdit);

    contentTextEdit = new QTextEdit();
    contentTextEdit->setMinimumHeight(300);
    contentTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    insertContentButton = new QPushButton(tr("Insert"));
    addContentButton = new QPushButton(tr("Add"));
    deleteContentButton = new QPushButton(tr("Delete"));
    confirmContentButton = new QPushButton(tr("Confirm"));

    contentDialogButtonBox = new QDialogButtonBox;
    contentDialogButtonBox->addButton(insertContentButton, QDialogButtonBox::ActionRole);
    contentDialogButtonBox->addButton(addContentButton, QDialogButtonBox::ActionRole);
    contentDialogButtonBox->addButton(deleteContentButton, QDialogButtonBox::ActionRole);
    contentDialogButtonBox->addButton(confirmContentButton, QDialogButtonBox::ActionRole);

//    connect(insertContentButton, SIGNAL(clicked()), this, SLOT(insertContent()));
//    connect(addContentButton, SIGNAL(clicked()), this, SLOT(addContent()));
//    connect(deleteContentButton, SIGNAL(clicked()), this, SLOT(deleteContent()));
//    connect(confirmContentButton, SIGNAL(clicked()), this, SLOT(confirmContent()));

    //생성된 요소를 레이아웃에 담는다.
    contentPanelLayout = new QVBoxLayout;
    contentPanelLayout->addLayout(contentidLayout);
    contentPanelLayout->addWidget(contentTextEdit);
    contentPanelLayout->addWidget(contentDialogButtonBox);
    contentPanelLayout->setAlignment(contentidLayout,Qt::AlignLeft);

    //레이아웃을 프레임에 붙인다.
    contentPanel->setLayout(contentPanelLayout);
}
