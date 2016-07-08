#include "MainForm.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
{
    this->setFocus(); //default 포커스를 옮기지 않으면 생성 즉시 첫번째 ListView에 포커스가 가서 선택되고, 연이어 두번째 ListView에 데이터가 표시됨
    sqlDb = new CKDBEngine();
    sqlDb->connectDb("QSQLITE", "Book_Summary.sqlite");

    //화면에 표시할 요소들을 담은 패널(프레임)을 생성한다.
    createCategoryPanel();
    createContentPanel();

    ///메인레이아웃 생성
    {
        //스플리터를 생성한다.
        mainSplitter = new QSplitter(Qt::Horizontal);
        mainSplitter->setFrameStyle(QFrame::Panel|QFrame::Sunken);
        mainSplitter->setChildrenCollapsible(false); //스플리터 내부의 요소들이 사라지지 않도록 최소크기를 유지함

        //스플리터에 패널들을 붙인다.
        mainSplitter->addWidget(categoryPanel);
        mainSplitter->addWidget(contentPanel);
        //스플리터 내부의 인덱스가 1(두번째)인 컨트롤만 늘어남
        //두번째 인자는 다른 인덱스(예를 들어 첫번째)의 컨트롤 대비 늘어나는 비율, 0이면 안늘어남
        mainSplitter->setStretchFactor(1,1);
        //레이아웃을 생성하여 스플리터를 붙인다.
        mainLayout = new QVBoxLayout;
        mainLayout->addWidget(mainSplitter);

        setLayout(mainLayout);
    }
}

MainForm::~MainForm()
{

}

//Title을 표시할 패널을 생성한다.
void MainForm::createCategoryPanel()
{
    //프레임을 생성한다.
    categoryPanel = new QFrame;
    categoryPanel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    /*프레임 안에 나타낼 각종 요소를 생성한다.*/

    //데이터를 표시할 리스트뷰를 생성
    categoryLevel1Label = new QLabel(tr("Primary Category"));
    categoryLevel1ListView = new QListView;

    categoryLevel1ListView->setModel(sqlDb->modelCategoryLevel1);
    categoryLevel1ListView->setModelColumn(1);
    connect(categoryLevel1ListView->selectionModel(),
            SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
            this, SLOT(updateCategoryLevel2ListView()));
    connect(categoryLevel1ListView->selectionModel(),
            SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
            this, SLOT(updateCategoryLevel3ListView()));
    connect(categoryLevel1ListView->selectionModel(),
            SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
            this, SLOT(updateContentPanel()));
    categoryLevel2Label = new QLabel(tr("Secondary Category"));
    categoryLevel2ListView = new QListView;
    categoryLevel2ListView->setModel(sqlDb->modelCategoryLevel2);
    categoryLevel2ListView->setModelColumn(2);
    connect(categoryLevel2ListView->selectionModel(),
            SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
            this, SLOT(updateCategoryLevel3ListView()));
    connect(categoryLevel2ListView->selectionModel(),
            SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
            this, SLOT(updateContentPanel()));
    categoryLevel3Label = new QLabel(tr("Tertiary Category"));
    categoryLevel3ListView = new QListView;
    categoryLevel3ListView->setModel(sqlDb->modelCategoryLevel3);
    categoryLevel3ListView->setModelColumn(3);
    connect(categoryLevel3ListView->selectionModel(),
            SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
            this, SLOT(updateContentPanel()));

    //그리드 레이아웃 생성후 컨트롤들 추가
    categoryGridLayout = new QGridLayout;
    categoryGridLayout->addWidget(categoryLevel1Label,0,0,1,2);
    categoryGridLayout->addWidget(categoryLevel1ListView,1,0,6,2);
    categoryGridLayout->addWidget(categoryLevel2Label,7,0,1,2);
    categoryGridLayout->addWidget(categoryLevel2ListView,8,0,6,2);
    categoryGridLayout->addWidget(categoryLevel3Label,14,0,1,2);
    categoryGridLayout->addWidget(categoryLevel3ListView,15,0,6,2);

    //조작버튼부를 생성
    insertCategoryButton = new QPushButton(tr("Insert"));
    addCategoryButton = new QPushButton(tr("Add"));
    deleteCategoryButton = new QPushButton(tr("Delete"));
    confirmCategoryButton = new QPushButton(tr("Confirm"));

    //조작버튼부를 그룹화
    categoryDialogButtonBox = new QDialogButtonBox;
    categoryDialogButtonBox->addButton(insertCategoryButton, QDialogButtonBox::ActionRole);
    categoryDialogButtonBox->addButton(addCategoryButton, QDialogButtonBox::ActionRole);
    categoryDialogButtonBox->addButton(deleteCategoryButton, QDialogButtonBox::ActionRole);
    categoryDialogButtonBox->addButton(confirmCategoryButton, QDialogButtonBox::ActionRole);

    //조작버튼을 슬롯함수와 연결
    connect(insertCategoryButton, SIGNAL(clicked()), this, SLOT(insertCategory()));
    connect(addCategoryButton, SIGNAL(clicked()), this, SLOT(addCategory()));
    connect(deleteCategoryButton, SIGNAL(clicked()), this, SLOT(deleteCategory()));
    connect(confirmCategoryButton, SIGNAL(clicked()), this, SLOT(confirmCategory()));

    //생성된 요소를 레이아웃에 담는다.
    categoryPanelLayout = new QVBoxLayout;
    categoryPanelLayout->addLayout(categoryGridLayout);
    categoryPanelLayout->addWidget(categoryDialogButtonBox);

    //레이아웃을 프레임에 붙인다.
    categoryPanel->setLayout(categoryPanelLayout);
}

//Content를 표시할 패널을 생성한다.
void MainForm::createContentPanel()
{
    //프레임을 생성한다.
    contentPanel = new QFrame;
    contentPanel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    /*프레임 안에 나타낼 각종 요소를 생성한다.*/

    //타이틀을 나타낼 요소를 생성
    titleLabel = new QLabel(tr("Title"));
    titleLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    titleLabel->setContentsMargins(0,5,0,0); // 이 값을 안주면 라벨의 텍스트가 약간 위쪽에 있게 됨
    titleLineEdit = new QLineEdit;
    titleSearchPushButton = new QPushButton(tr("&Find"));
    titleSearchPushButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    titleFormLayout = new QFormLayout;
    titleFormLayout->addRow(titleLabel,titleLineEdit);

    titleHBoxLayout = new QHBoxLayout;
    titleHBoxLayout->addLayout(titleFormLayout);
    titleHBoxLayout->addWidget(titleSearchPushButton);

    bodyTextEdit = new QTextEdit();
    bodyTextEdit->setMinimumHeight(300);
    bodyTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    insertContentButton = new QPushButton(tr("Insert"));
    addContentButton = new QPushButton(tr("Add"));
    deleteContentButton = new QPushButton(tr("Delete"));
    confirmContentButton = new QPushButton(tr("Confirm"));

    contentDialogButtonBox = new QDialogButtonBox;
    contentDialogButtonBox->addButton(insertContentButton, QDialogButtonBox::ActionRole);
    contentDialogButtonBox->addButton(addContentButton, QDialogButtonBox::ActionRole);
    contentDialogButtonBox->addButton(deleteContentButton, QDialogButtonBox::ActionRole);
    contentDialogButtonBox->addButton(confirmContentButton, QDialogButtonBox::ActionRole);

    //조작버튼을 슬롯함수와 연결
    connect(insertContentButton, SIGNAL(clicked()), this, SLOT(insertContent()));
    connect(addContentButton, SIGNAL(clicked()), this, SLOT(addContent()));
    connect(deleteContentButton, SIGNAL(clicked()), this, SLOT(deleteContent()));
    connect(confirmContentButton, SIGNAL(clicked()), this, SLOT(confirmContent()));

    //생성된 요소를 레이아웃에 담는다.
    contentPanelLayout = new QVBoxLayout;
    contentPanelLayout->addLayout(titleHBoxLayout);
    contentPanelLayout->addWidget(bodyTextEdit);
    contentPanelLayout->addWidget(contentDialogButtonBox);

    //레이아웃을 프레임에 붙인다.
    contentPanel->setLayout(contentPanelLayout);

    //생성된 요소에 데이터를 연결함
    sqlDb->mapperContent->addMapping(titleLineEdit, 4);
    sqlDb->mapperContent->addMapping(bodyTextEdit, 5);
}

//첫번째 Category 선택에 따라 두번째 Category 변경
void MainForm::updateCategoryLevel2ListView()
{
    QModelIndex index = categoryLevel1ListView->currentIndex();
    if(index.isValid()){
        QSqlRecord record = sqlDb->modelCategoryLevel1->record(index.row());
        int id = record.value("idLevel1").toInt();
        sqlDb->modelCategoryLevel2->setFilter(QString("idLevel1 = %1").arg(id));
    }else{
        sqlDb->modelCategoryLevel2->setFilter("idLevel1 = -1");
    }
    sqlDb->modelCategoryLevel2->select();
}

//첫번째 또는 두번째 Category 선택에 따라 세번째 Category 변경
void MainForm::updateCategoryLevel3ListView()
{
    QModelIndex index = categoryLevel2ListView->currentIndex();
    if(index.isValid()){
        QSqlRecord record = sqlDb->modelCategoryLevel2->record(index.row());
        int id = record.value("idLevel2").toInt();
        sqlDb->modelCategoryLevel3->setFilter(QString("idLevel2 = %1").arg(id));
    }else{
        sqlDb->modelCategoryLevel3->setFilter("idLevel2 = -1");
    }
    sqlDb->modelCategoryLevel3->select();
}

//첫번째, 두번째 및 세번째 Category 선택에 따라 Content 패널 변경
void MainForm::updateContentPanel()
{
    titleLineEdit->clear();
    bodyTextEdit->clear();

    int id;
    QModelIndex index = categoryLevel3ListView->currentIndex();
    if(index.isValid()){
        QSqlRecord recordCategory = sqlDb->modelCategoryLevel3->record(index.row());
        id = recordCategory.value("idLevel3").toInt();
        sqlDb->modelContent->setFilter(QString("colCategoryLevel3 = %1").arg(id));
    }else{
        sqlDb->modelContent->setFilter("colCategoryLevel3 = -1");

    }
    sqlDb->modelContent->select();

    //데이터가 다수 개일 수가 있으므로 for문을 돌려서 첫번째 데이터를 표시
    for (int row = 0; row < sqlDb->modelContent->rowCount(); ++row) {
        QSqlRecord recordContent = sqlDb->modelContent->record(row);
        if (recordContent.value(3).toInt() == id) {
            sqlDb->mapperContent->setCurrentIndex(row);
            break;
        }
    }
}

//Category 데이터 조작 함수들
void MainForm::insertCategory()
{
    int row = categoryLevel3ListView->selectionModel()->currentIndex().row();
    sqlDb->modelCategoryLevel3->insertRow(row);
    QModelIndex index = sqlDb->modelCategoryLevel3->index(row, 3);
    categoryLevel3ListView->setCurrentIndex(index);
    categoryLevel3ListView->edit(index);
}
void MainForm::addCategory()
{
    int row = sqlDb->modelCategoryLevel3->rowCount();
    sqlDb->modelCategoryLevel3->insertRow(row);
    QModelIndex index = sqlDb->modelCategoryLevel3->index(row, 3);
    categoryLevel3ListView->setCurrentIndex(index);
    categoryLevel3ListView->edit(index);
}
void MainForm::deleteCategory()
{

}
void MainForm::confirmCategory()
{

}

//Content 데이터 조작 함수들
void MainForm::insertContent()
{

}
void MainForm::addContent()
{

}
void MainForm::deleteContent()
{

}
void MainForm::confirmContent()
{

}
