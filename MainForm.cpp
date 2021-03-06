#include "MainForm.h"
#include <QApplication>
#include <QMessageBox>
#include <QHeaderView>
#include <QWebEnginePage>

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

//Category를 표시할 패널을 생성한다.
void MainForm::createCategoryPanel()
{

    //리스트뷰1 생성
    {
        categoryLevel1Label = new QLabel(tr("Primary Category"));
        categoryLevel1ListView = new QListView;

        categoryLevel1ListView->setModel(sqlDb->modelCategoryLevel1);
        categoryLevel1ListView->setModelColumn(1);
        categoryLevel1ListView->setObjectName("ListView_Level1");
        categoryLevel1ListView->setFrameShape(QFrame::WinPanel);
        categoryLevel1ListView->setFrameShadow(QFrame::Plain);

        connect(categoryLevel1ListView->selectionModel(),
                SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
                this, SLOT(updateCategoryLevel2ListView()));
        connect(categoryLevel1ListView->selectionModel(),
                SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
                this, SLOT(updateCategoryLevel3ListView()));
        connect(categoryLevel1ListView->selectionModel(),
                SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
                this, SLOT(updateContentPanel()));
    }
    //리스트뷰2 생성
    {
        categoryLevel2Label = new QLabel(tr("Secondary Category"));
        categoryLevel2ListView = new QListView;
        categoryLevel2ListView->setModel(sqlDb->modelCategoryLevel2);
        categoryLevel2ListView->setModelColumn(2);
        categoryLevel2ListView->setObjectName("ListView_Level2");
        categoryLevel2ListView->setFrameShape(QFrame::WinPanel);
        categoryLevel2ListView->setFrameShadow(QFrame::Sunken);

        connect(categoryLevel2ListView->selectionModel(),
                SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
                this, SLOT(updateCategoryLevel3ListView()));
        connect(categoryLevel2ListView->selectionModel(),
                SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
                this, SLOT(updateContentPanel()));
    }
    //리스트뷰3 생성
    {
        categoryLevel3Label = new QLabel(tr("Tertiary Category"));
        categoryLevel3ListView = new QListView;
        categoryLevel3ListView->setModel(sqlDb->modelCategoryLevel3);
        categoryLevel3ListView->setModelColumn(3);
        categoryLevel3ListView->setObjectName("ListView_Level3");
        categoryLevel3ListView->setFrameShape(QFrame::WinPanel);
        categoryLevel3ListView->setFrameShadow(QFrame::Sunken);

        connect(categoryLevel3ListView->selectionModel(),
                SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
                this, SLOT(updateContentPanel()));
    }
    //그리드 레이아웃 생성후 리스트뷰들 추가
    {
        categoryGridLayout = new QGridLayout;
        categoryGridLayout->addWidget(categoryLevel1Label,0,0,1,2);
        categoryGridLayout->addWidget(categoryLevel1ListView,1,0,6,2);
        categoryGridLayout->addWidget(categoryLevel2Label,7,0,1,2);
        categoryGridLayout->addWidget(categoryLevel2ListView,8,0,6,2);
        categoryGridLayout->addWidget(categoryLevel3Label,14,0,1,2);
        categoryGridLayout->addWidget(categoryLevel3ListView,15,0,6,2);
    }
    //조작버튼부를 생성
    {
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
    }
    //생성된 요소를 레이아웃에 담는다.
    {
        categoryPanelLayout = new QVBoxLayout;
        categoryPanelLayout->addLayout(categoryGridLayout);
        categoryPanelLayout->addWidget(categoryDialogButtonBox);
    }
    //프레임을 생성하여 레이아웃을 프레임에 붙인다.
    {
        categoryPanel = new QFrame;
        categoryPanel->setFrameStyle(QFrame::Panel|QFrame::Sunken);
        categoryPanel->setLayout(categoryPanelLayout);
    }

    //어떤 컨트롤이 포커스를 받았는지 알려주는 시그널과 이를 받아 컨트롤의 이름에 대한 색인을 반환하는 슬롯함수를 연결
    connect(qApp, SIGNAL(focusChanged(QWidget*,QWidget*)),
      SLOT(focusChanged(QWidget*,QWidget*)));
}

//Content를 표시할 패널을 생성한다.
void MainForm::createContentPanel()
{
    //타이틀영역 요소를 생성
    {
        titleLabel = new QLabel(tr("Question"));
        titleLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        titleLabel->setContentsMargins(0,5,0,0); // 이 값을 안주면 라벨의 텍스트가 약간 위쪽에 있게 됨
//        titleLineEdit = new QLineEdit;
        bodyTextEdit = new QPlainTextEdit();
        bodyTextEdit->setMinimumHeight(50);
        bodyTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//        titleLabel01 = new QLabel(tr("①"));
//        titleLabel01->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
//        titleLabel01->setContentsMargins(0,5,0,0); // 이 값을 안주면 라벨의 텍스트가 약간 위쪽에 있게 됨
//        titleLineEdit01 = new QLineEdit;

//        titleLabel02 = new QLabel(tr("②"));
//        titleLabel02->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
//        titleLabel02->setContentsMargins(0,5,0,0); // 이 값을 안주면 라벨의 텍스트가 약간 위쪽에 있게 됨
//        titleLineEdit02 = new QLineEdit;

//        titleLabel03 = new QLabel(tr("③"));
//        titleLabel03->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
//        titleLabel03->setContentsMargins(0,5,0,0); // 이 값을 안주면 라벨의 텍스트가 약간 위쪽에 있게 됨
//        titleLineEdit03 = new QLineEdit;

        titleLabel04 = new QLabel(tr("Answer"));
        titleLabel04->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        titleLabel04->setContentsMargins(0,5,0,0); // 이 값을 안주면 라벨의 텍스트가 약간 위쪽에 있게 됨
        titleLineEdit04 = new QComboBox;
        titleLineEdit04->setEditable(true);
        titleLineEdit04->setEditText("-");
        titleLineEdit04->addItem("O");
        titleLineEdit04->addItem("X");
        titleLineEdit04->addItem("1)");
        titleLineEdit04->addItem("2)");
        titleLineEdit04->addItem("3)");
        titleLineEdit04->addItem("4)");
//        QLineEdit *le = new QLineEdit;
//        titleLineEdit04->setLineEdit(le);
//        titleLineEdit04->lineEdit()->setPlaceholderText("Select...");

        titleFormLayout = new QFormLayout;
        titleFormLayout->addRow(titleLabel, bodyTextEdit);
//        titleFormLayout->addRow(titleLabel01, titleLineEdit01);
//        titleFormLayout->addRow(titleLabel02, titleLineEdit02);
//        titleFormLayout->addRow(titleLabel03, titleLineEdit03);
        titleFormLayout->addRow(titleLabel04, titleLineEdit04);

        titleSearchPushButton = new QPushButton(tr("&Search"));
        titleSearchPushButton->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

        QSpacerItem *vspacer = new QSpacerItem(40,20,QSizePolicy::Minimum,QSizePolicy::Expanding);

        QVBoxLayout *searchButtonLayout = new QVBoxLayout;
        searchButtonLayout->addWidget(titleSearchPushButton);
        searchButtonLayout->addItem(vspacer);

        titleHBoxLayout = new QHBoxLayout;
        titleHBoxLayout->addLayout(titleFormLayout);
        titleHBoxLayout->addLayout(searchButtonLayout);
    }
    //데이터 표시영역(WebView 영역) 생성
    {
        //    bodyTextEdit = new QPlainTextEdit();
        //    bodyTextEdit->setMinimumHeight(300);
        //    bodyTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        bodyWebView = new QWebEngineView;
        bodyWebView->setMinimumHeight(100);
        bodyWebView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        QString CurDir =  qApp->applicationDirPath();
        QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
        bodyWebView->setUrl(url);
        bodyWebView->installEventFilter(this);//웹뷰로부터 오는 이벤트를 받겠다는 뜻
    }
    //테이블뷰의 생성
    {
        contentTableView = new QTableView;
        contentTableView->setModel(sqlDb->modelContent);
        contentTableView->hideColumn(0);
        contentTableView->hideColumn(1);
        contentTableView->hideColumn(4);
        contentTableView->hideColumn(5);
        contentTableView->setSelectionMode(QAbstractItemView::SingleSelection);
        contentTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        contentTableView->resizeColumnsToContents();
        contentTableView->setColumnWidth(2,250);
        contentTableView->horizontalHeader()->setStretchLastSection(true);
        contentTableView->setMinimumHeight(150);
        //contentTableView->sortByColumn(2,Qt::AscendingOrder);

        connect(contentTableView->selectionModel(),
                SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
                this, SLOT(contentFromTableModel(QModelIndex)));
        //contentTableView->show();
    }
    //Content 조작버튼의 생성
    {
        addContentButton = new QPushButton(tr("Add"));
        deleteContentButton = new QPushButton(tr("Delete"));
        confirmContentButton = new QPushButton(tr("Confirm"));
        printBodyButton = new QPushButton(tr("Print"));
        printReportButton = new QPushButton(tr("Report"));


        contentDialogButtonBox = new QDialogButtonBox;
        contentDialogButtonBox->addButton(addContentButton, QDialogButtonBox::ActionRole);
        contentDialogButtonBox->addButton(deleteContentButton, QDialogButtonBox::ActionRole);
        contentDialogButtonBox->addButton(confirmContentButton, QDialogButtonBox::ActionRole);
        contentDialogButtonBox->addButton(printBodyButton,QDialogButtonBox::ActionRole);
        contentDialogButtonBox->addButton(printReportButton, QDialogButtonBox::ActionRole);
    }
    //조작버튼을 슬롯함수와 연결
    {
        connect(titleSearchPushButton, SIGNAL(clicked()), this, SLOT(searchContent()));
        connect(addContentButton, SIGNAL(clicked()), this, SLOT(addContent()));
        connect(deleteContentButton, SIGNAL(clicked()), this, SLOT(deleteContent()));
        connect(confirmContentButton, SIGNAL(clicked()), this, SLOT(confirmContent()));
        connect(printBodyButton,SIGNAL(clicked()), this, SLOT(printBody()));
        connect(printReportButton,SIGNAL(clicked()), this, SLOT(printReport()));
    }
    //생성된 요소를 레이아웃에 담는다.
    {
        contentPanelLayout = new QVBoxLayout;
        contentPanelLayout->addLayout(titleHBoxLayout);
        //  contentPanelLayout->addWidget(bodyTextEdit);
        contentPanelLayout->addWidget(bodyWebView);
        contentPanelLayout->addWidget(contentTableView);
        contentPanelLayout->addWidget(contentDialogButtonBox);
    }
    //프레임을 생성하여 프레임에 레이아웃을 붙인다.
    {
        contentPanel = new QFrame;
        contentPanel->setFrameStyle(QFrame::Panel|QFrame::Sunken);
        contentPanel->setLayout(contentPanelLayout);
    }

    //생성된 요소와 데이터를 연동함
    sqlDb->mapperContent->addMapping(bodyTextEdit, 2);
    sqlDb->mapperContent->addMapping(titleLineEdit04,5);
    //sqlDb->mapperContent->addMapping(bodyTextEdit, 3);

    //insert QWebView object to javascript.
    //bodyWebView->page()->mainFrame()->addToJavaScriptWindowObject("hostObject", this);
    //bodyWebView->page()->mainFrame()->evaluateJavaScript("tinyMCE.get('mytextarea').execCommand('mceFullScreen');");
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
    changeModel(sqlDb->modelContent);
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
    changeModel(sqlDb->modelContent);
}

//첫번째, 두번째 및 세번째 Category 선택에 따라 Content 패널 변경
void MainForm::updateContentPanel()
{
    bodyTextEdit->clear();
    QModelIndex index;
    QString bodyString;

    switch(focusedWidget){
        case 3:
            categoryLevel1ListView->setFrameShadow(QFrame::Sunken);
            categoryLevel2ListView->setFrameShadow(QFrame::Sunken);
            categoryLevel3ListView->setFrameShadow(QFrame::Plain);

            int idLevel3;
            index = categoryLevel3ListView->currentIndex();
            if(index.isValid()){
                QSqlRecord recordCategory = sqlDb->modelCategoryLevel3->record(index.row());
                idLevel3 = recordCategory.value("idLevel3").toInt();
                sqlDb->modelContent->setFilter(QString("colCategoryIdLevel3 = %1").arg(idLevel3));
            }else{
                sqlDb->modelContent->setFilter("colCategoryIdLevel3 = -1");
            }
            sqlDb->modelContent->select();
            changeModel(sqlDb->modelContent);
//            sqlDb->mapperContent->setCurrentIndex(0);
//            //replace처리를 하지 않으면 개행문자에서 출력이 잘린다(multiline 처리)

//            bodyString = sqlDb->modelContent->record(0).value("colBody").toString();
//            bodyWebView->page()->mainFrame()->evaluateJavaScript(QString("tinyMCE.activeEditor.setContent('%1')").arg(bodyString).replace("\n","\\n"));
            break;
        case 2:
            categoryLevel1ListView->setFrameShadow(QFrame::Sunken);
            categoryLevel2ListView->setFrameShadow(QFrame::Plain);
            categoryLevel3ListView->setFrameShadow(QFrame::Sunken);

            int idLevel2;
            index = categoryLevel2ListView->currentIndex();
            if(index.isValid()){
                QSqlRecord recordCategory = sqlDb->modelCategoryLevel2->record(index.row());
                idLevel2 = recordCategory.value("idLevel2").toInt();
                sqlDb->modelContent->setFilter(QString("colCategoryIdLevel2 = %1").arg(idLevel2));
            }else{
                sqlDb->modelContent->setFilter("colCategoryIdLevel2 = -1");
            }
            sqlDb->modelContent->select();
            changeModel(sqlDb->modelContent);
//            sqlDb->mapperContent->setCurrentIndex(0);
//            //replace처리를 하지 않으면 개행문자에서 출력이 잘린다(multiline 처리)

//            bodyString = sqlDb->modelContent->record(0).value("colBody").toString();
//            bodyWebView->page()->mainFrame()->evaluateJavaScript(QString("tinyMCE.activeEditor.setContent('%1')").arg(bodyString).replace("\n","\\n"));
            break;

        case 1:
            categoryLevel1ListView->setFrameShadow(QFrame::Plain);
            categoryLevel2ListView->setFrameShadow(QFrame::Sunken);
            categoryLevel3ListView->setFrameShadow(QFrame::Sunken);
            break;
    }
}

//포커스를 받은 리스트뷰의 색인을 저장해주는 슬롯함수
void MainForm::focusChanged(QWidget *, QWidget *to)
{
    //화면을 닫거나 다른 프로그램으로 전환해서 현재 프로그램 내에 포커스가 없는 경우
    //그냥 처리 없이 지나친다.
    if(to == 0){return;}

    //그렇지 않으면 현재 포커스를 받은 컨트롤을 확인하고 색인을 저장한다.
    if(to->objectName()=="ListView_Level1"){
        focusedWidget = 1;
        return;
    }else if(to->objectName()=="ListView_Level2"){
        focusedWidget = 2;
        return;
    }else if(to->objectName()=="ListView_Level3"){
        focusedWidget = 3;
        return;
    }

    return;
}

//Category 데이터 조작 함수들
void MainForm::insertCategory()
{
    if(focusedWidget == 3)
    {
        int row = categoryLevel3ListView->selectionModel()->currentIndex().row();
        sqlDb->modelCategoryLevel3->insertRow(row);
        QModelIndex index = sqlDb->modelCategoryLevel3->index(row, 3);
        categoryLevel3ListView->setCurrentIndex(index);
        categoryLevel3ListView->edit(index);
        return;
    }else if(focusedWidget == 2){
        int row = categoryLevel2ListView->selectionModel()->currentIndex().row();
        sqlDb->modelCategoryLevel2->insertRow(row);
        QModelIndex index = sqlDb->modelCategoryLevel2->index(row, 2);
        categoryLevel2ListView->setCurrentIndex(index);
        categoryLevel2ListView->edit(index);
        return;
    }else if(focusedWidget == 1){
        int row = categoryLevel1ListView->selectionModel()->currentIndex().row();
        sqlDb->modelCategoryLevel1->insertRow(row);
        QModelIndex index = sqlDb->modelCategoryLevel1->index(row, 1);
        categoryLevel1ListView->setCurrentIndex(index);
        categoryLevel1ListView->edit(index);
        return;
    }
}
void MainForm::addCategory()
{
    if(focusedWidget == 3)
    {
        int row = sqlDb->modelCategoryLevel3->rowCount();
        sqlDb->modelCategoryLevel3->insertRow(row);
        QModelIndex index = sqlDb->modelCategoryLevel3->index(row, 3);
        categoryLevel3ListView->setCurrentIndex(index);
        categoryLevel3ListView->edit(index);
        return;

    }else if(focusedWidget == 2){

        int row = sqlDb->modelCategoryLevel2->rowCount();
        sqlDb->modelCategoryLevel2->insertRow(row);
        QModelIndex index = sqlDb->modelCategoryLevel2->index(row, 2);
        categoryLevel2ListView->setCurrentIndex(index);
        categoryLevel2ListView->edit(index);
        return;

    }else if(focusedWidget == 1){

        int row = sqlDb->modelCategoryLevel1->rowCount();
        sqlDb->modelCategoryLevel1->insertRow(row);
        QModelIndex index = sqlDb->modelCategoryLevel1->index(row, 1);
        categoryLevel1ListView->setCurrentIndex(index);
        categoryLevel1ListView->edit(index);
        return;
    }
}
void MainForm::deleteCategory()
{
    //포커스를 받은 위젯이 세 번째 리스트뷰임
    if(focusedWidget == 3){
        //삭제하려는데 선택된 데이터가 없으면 리턴함
        QModelIndex index = categoryLevel3ListView->currentIndex();
         if (!index.isValid())
             return;

         QSqlDatabase::database().transaction();
         QSqlRecord record = sqlDb->modelCategoryLevel3->record(index.row());
         int idLevel3 = record.value(0).toInt();//0번째 컬럼, 즉 idLevel3의 데이터를 뽑는다.
         int numContents = 0;

         //tblContent 테이블에서 foreign key인 colCategoryIdLevel3가 idLevel3와 같은 경우의 갯수를 센다.
         QSqlQuery query(QString("SELECT COUNT(*) FROM tblContent "
                                 "WHERE colCategoryIdLevel3 = %1").arg(idLevel3));
         if (query.next())
             numContents = query.value(0).toInt();
         //Category Level3에 걸리는 Content가 있다면 사용자의 의사를 물어본다.
         if (numContents > 0) {
             int r = QMessageBox::warning(this, tr("Delete Category"),
                         tr("Delete %1 and all its contents?")
                         .arg(record.value(3).toString()),
                         QMessageBox::Yes | QMessageBox::No);
             if (r == QMessageBox::No) {
                 QSqlDatabase::database().rollback();
                 return;
             }
             //사용자가 Yes를 눌렀다면 그대로 진행하여 Category Level3에 속한 Content들을 삭제함
             query.exec(QString("DELETE FROM tblContent "
                                "WHERE colCategoryIdLevel3 = %1").arg(idLevel3));
         }
         //Category Level3에 걸리는 Content가 없다면 그냥 삭제한다.
         sqlDb->modelCategoryLevel3->removeRow(index.row());
         sqlDb->modelCategoryLevel3->submitAll();
         QSqlDatabase::database().commit();

         updateCategoryLevel3ListView();
         categoryLevel3ListView->setFocus();

         return;
    }

    //포커스를 받은 위젯이 두 번째 리스트뷰임
    if(focusedWidget == 2){
    QMessageBox::information(this, tr("Delete Category"),
                         tr("Delete Category Level 3 first."),
                         QMessageBox::Abort);
    }
    //포커스를 받은 위젯이 첫 번째 리스트뷰임
    if(focusedWidget == 1){
    QMessageBox::information(this, tr("Delete Category"),
                         tr("Delete Category Level 3 and 2 first."),
                         QMessageBox::Abort);
    }
}
void MainForm::confirmCategory()
{
    if(focusedWidget == 3){

        //삽입한 빈줄 내부의 itemText컬럼의 index값을 알아내어 그 위치에 값을 대입한다.
        int colNum_idLevel2 = sqlDb->modelCategoryLevel3->fieldIndex("idLevel2");
        int colNum_idLevel1 = sqlDb->modelCategoryLevel3->fieldIndex("idLevel1");
        int colNum_colCategoryLevel3 = sqlDb->modelCategoryLevel3->fieldIndex("colCategoryLevel3");
        int rowNum = categoryLevel3ListView->selectionModel()->currentIndex().row();

        QModelIndex idx_idLevel2 = sqlDb->modelCategoryLevel3->index(rowNum, colNum_idLevel2);
        QModelIndex idx_idLevel1 = sqlDb->modelCategoryLevel3->index(rowNum, colNum_idLevel1);
        QModelIndex idx_colCategoryLevel3 = sqlDb->modelCategoryLevel3->index(rowNum, colNum_colCategoryLevel3);

        QModelIndex index2 = categoryLevel2ListView->currentIndex();
        QSqlRecord record2 = sqlDb->modelCategoryLevel2->record(index2.row());
        int id2 = record2.value("idLevel2").toInt();

        QModelIndex index1 = categoryLevel1ListView->currentIndex();
        QSqlRecord record1 = sqlDb->modelCategoryLevel1->record(index1.row());
        int id1 = record1.value("idLevel1").toInt();

        sqlDb->modelCategoryLevel3->setData(idx_idLevel2, id2);
        sqlDb->modelCategoryLevel3->setData(idx_idLevel1, id1);
        sqlDb->modelCategoryLevel3->setData(idx_colCategoryLevel3, categoryLevel3ListView->currentIndex().data().toString());

        sqlDb->modelCategoryLevel3->submitAll();

    }else if(focusedWidget == 2){

        //삽입한 빈줄 내부의 itemText컬럼의 index값을 알아내어 그 위치에 값을 대입한다.
        int colNum_idLevel1 = sqlDb->modelCategoryLevel2->fieldIndex("idLevel1");
        int colNum_colCategoryLevel2 = sqlDb->modelCategoryLevel2->fieldIndex("colCategoryLevel2");
        int rowNum = categoryLevel2ListView->selectionModel()->currentIndex().row();
        QModelIndex idx_idLevel1 = sqlDb->modelCategoryLevel2->index(rowNum, colNum_idLevel1);
        QModelIndex idx_colCategoryLevel2 = sqlDb->modelCategoryLevel2->index(rowNum, colNum_colCategoryLevel2);

        QModelIndex index1 = categoryLevel1ListView->currentIndex();
        QSqlRecord record1 = sqlDb->modelCategoryLevel1->record(index1.row());
        int id1 = record1.value("idLevel1").toInt();

        sqlDb->modelCategoryLevel2->setData(idx_idLevel1, id1);
        sqlDb->modelCategoryLevel2->setData(idx_colCategoryLevel2, categoryLevel2ListView->currentIndex().data().toString());

        sqlDb->modelCategoryLevel2->submitAll();

    }else if(focusedWidget == 1){

        //삽입한 빈줄 내부의 itemText컬럼의 index값을 알아내어 그 위치에 값을 대입한다.
        int colNum_colCategoryLevel1 = sqlDb->modelCategoryLevel1->fieldIndex("colCategoryLevel1");
        int rowNum = categoryLevel1ListView->selectionModel()->currentIndex().row();
        QModelIndex idx_colCategoryLevel1 = sqlDb->modelCategoryLevel1->index(rowNum, colNum_colCategoryLevel1);

        sqlDb->modelCategoryLevel1->setData(idx_colCategoryLevel1, categoryLevel1ListView->currentIndex().data().toString());

        sqlDb->modelCategoryLevel1->submitAll();
    }
}

//Content 데이터 조작 함수들
void MainForm::searchContent()
{
    QString target("%"+bodyTextEdit->toPlainText()+"%");
    QSqlQuery qryFilter;
    QString qryStr = "SELECT * FROM tblContent WHERE colTitle LIKE :target";
    qryFilter.prepare(qryStr);
    qryFilter.bindValue(":target", target);
    qryFilter.exec();

    queryModel = new QSqlQueryModel;
    queryModel->setQuery(qryFilter);

//    //sorting등을 담당하는 모델
//    proxyModel = new QSortFilterProxyModel;
//    proxyModel->setSourceModel(queryModel);
//    contentTableView->setModel(proxyModel);
//    //proxyModel->sort(2,Qt::DescendingOrder);
    changeModel(queryModel);
}
void MainForm::changeModel(QSqlQueryModel *model)
{
    contentTableView->setModel(model);

    sqlDb->mapperContent->clearMapping();
    sqlDb->mapperContent->setModel(model);
    sqlDb->mapperContent->addMapping(bodyTextEdit, 2);
    sqlDb->mapperContent->addMapping(titleLineEdit04, 5);

    titleLineEdit04->setEditText("Select...");
    QString CurDir =  qApp->applicationDirPath();
    QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
    bodyWebView->setUrl(url);

    connect(contentTableView->selectionModel(),
            SIGNAL(currentRowChanged(const QModelIndex &, const QModelIndex &)),
            this, SLOT(contentFromQueryModel(QModelIndex)));
}
void MainForm::changeModel(QSqlTableModel *model)
{
    contentTableView->setModel(model);

    sqlDb->mapperContent->clearMapping();
    sqlDb->mapperContent->setModel(model);
    sqlDb->mapperContent->addMapping(bodyTextEdit, 2);
    sqlDb->mapperContent->addMapping(titleLineEdit04, 5);

    titleLineEdit04->setEditText("Select...");
    QString CurDir =  qApp->applicationDirPath();
    QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
    bodyWebView->setUrl(url);

    connect(contentTableView->selectionModel(),
            SIGNAL(currentRowChanged(QModelIndex,QModelIndex)),
            this,SLOT(contentFromTableModel(QModelIndex)));
}
void MainForm::addContent()
{
    //sqlDb->mapperContent->submit();//만약 현재 Content를 편집중에 Add버튼을 눌렀다면 입력중이었던 데이터는 저장해야 함

    int row = sqlDb->modelContent->rowCount();
    sqlDb->modelContent->insertRow(row);
    sqlDb->mapperContent->setCurrentIndex(row);

    bodyTextEdit->clear();
    titleLineEdit04->clearEditText();
    titleLineEdit04->setEditText("Select...");
    QString CurDir =  qApp->applicationDirPath();
    QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
    bodyWebView->setUrl(url);
    bodyTextEdit->setFocus();
}
void MainForm::deleteContent()
{
    int row = sqlDb->mapperContent->currentIndex();
    sqlDb->modelContent->removeRow(row);
    sqlDb->modelContent->submitAll();
    //sqlDb->mapperContent->submit();
    //매퍼의 현재 인덱스를 삭제된 바로 다음 행이 되게 하고, 삭제된 행이 마지막 행이었다면 지금의 마지막 행이 현재 인덱스가 되게 한다.
    sqlDb->mapperContent->setCurrentIndex(qMin(row, sqlDb->modelContent->rowCount() - 1));
    //replace처리를 하지 않으면 개행문자에서 출력이 잘린다(multiline 처리)
    titleLineEdit04->setEditText("Select...");
    QString bodyString;
    bodyString = sqlDb->modelContent->record(qMin(row, sqlDb->modelContent->rowCount() - 1)).value("colBody").toString();
    //bodyWebView->page()->mainFrame()->evaluateJavaScript(QString("tinyMCE.activeEditor.setContent('%1')").arg(bodyString).replace("\n","\\n"));
    bodyWebView->page()->runJavaScript(QString("tinyMCE.activeEditor.setContent('%1')").arg(bodyString).replace("\n","\\n"));
}
void MainForm::confirmContent()
{
    QModelIndex index;

    int idLevel3;
    index = categoryLevel3ListView->currentIndex();
    if(index.isValid()){
        QSqlRecord recordCategory = sqlDb->modelCategoryLevel3->record(index.row());
        idLevel3 = recordCategory.value("idLevel3").toInt();
    }

    int idLevel2;
    index = categoryLevel2ListView->currentIndex();
    if(index.isValid()){
        QSqlRecord recordCategory = sqlDb->modelCategoryLevel2->record(index.row());
        idLevel2 = recordCategory.value("idLevel2").toInt();
    }

    int row = sqlDb->mapperContent->currentIndex();
    QModelIndex idxCategoryIdLevel3 = sqlDb->modelContent->index(row,1);
    QModelIndex idxTitle = sqlDb->modelContent->index(row,2);
    QModelIndex idxBody = sqlDb->modelContent->index(row,3);
    QModelIndex idxCategoryIdLevel2 = sqlDb->modelContent->index(row,4);
    QModelIndex idxAnswer = sqlDb->modelContent->index(row,5);

    sqlDb->modelContent->setData(idxCategoryIdLevel3, idLevel3);
    sqlDb->modelContent->setData(idxTitle, bodyTextEdit->toPlainText());
    sqlDb->modelContent->setData(idxCategoryIdLevel2, idLevel2);
    sqlDb->modelContent->setData(idxAnswer, titleLineEdit04->currentText());
    //sqlDb->modelContent->setData(idxBody,bodyTextEdit->toPlainText());
    //비동기식이므로 콜백함수를 넣어 준다.
    bodyWebView->page()->runJavaScript(
                "tinyMCE.activeEditor.getContent();",
                [this, idxBody](const QVariant &result){this->sqlDb->modelContent->setData(idxBody, result.toString()); sqlDb->modelContent->submitAll();});
    //sqlDb->modelContent->setData(idxBody, bodyString);
    //sqlDb->modelContent->submitAll();

    bodyTextEdit->clear();
    titleLineEdit04->setEditText("Select...");
    QString CurDir =  qApp->applicationDirPath();
    QUrl url("file:///"+CurDir+"/QtinyMCE/tinymce4_base.html");
    bodyWebView->setUrl(url);
}
void MainForm::contentFromTableModel(QModelIndex index)
{
    int row = index.row();
    sqlDb->mapperContent->setCurrentIndex(row);
    //replace처리를 하지 않으면 개행문자에서 출력이 잘린다(multiline 처리)
    QString bodyString;
    bodyString = sqlDb->modelContent->record(row).value("colBody").toString();
    bodyWebView->page()->runJavaScript(QString("tinyMCE.activeEditor.setContent('%1')").arg(bodyString).replace("\n","\\n"));
}
void MainForm::contentFromQueryModel(QModelIndex index)
{
    int row = index.row();
    sqlDb->mapperContent->setCurrentIndex(row);
    //replace처리를 하지 않으면 개행문자에서 출력이 잘린다(multiline 처리)
    QString bodyString;
    bodyString = queryModel->record(row).value("colBody").toString();
    bodyWebView->page()->runJavaScript(QString("tinyMCE.activeEditor.setContent('%1')").arg(bodyString).replace("\n","\\n"));
}
//본문 인쇄
void MainForm::printBody()
{
    prntDevice = new QPrinter();
    prntPreviewDialog = new QPrintPreviewDialog(prntDevice, this);
    prntPreviewDialog->setWindowState(Qt::WindowMaximized);
    connect(prntPreviewDialog, SIGNAL(paintRequested(QPrinter*)), SLOT(slotPrint(QPrinter *)));
    prntPreviewDialog->exec();
}
void MainForm::slotPrint(QPrinter *printer)
{
    QWebEngineView *webviewPrint = new QWebEngineView();
    webviewPrint->setFixedSize(QSize(printer->width(),printer->height()));
    //QString printString;
    bodyWebView->page()->runJavaScript("tinyMCE.activeEditor.getContent();",
                                       [webviewPrint](const QVariant &result){webviewPrint->setHtml(result.toString());});
    //webviewPrint->setHtml(printString);
   //webviewPrint->setHtml(ui->webViewBody->page()->mainFrame()->toHtml());

    printer->setPaperSize(QPrinter::A4);
    printer->setOutputFormat(QPrinter::NativeFormat);
    printer->setOrientation(QPrinter::Portrait);
    printer->setResolution(120);  // DPI 세팅 Default로 96으로 되어있음
    QMargins m(25,50,25,50);
    printer->setPageMargins(m);
    webviewPrint->page()->print(printer, [this](const QVariant &result){this->slotHandlePagePrinted(result.toBool());});
}
void MainForm::slotHandlePagePrinted(bool result)
{
    Q_UNUSED(result);

    delete prntDevice;
    prntDevice = nullptr;
}

//리포트 인쇄
void MainForm::printReport()
{
    QString fileName = "printContentRpt.xml";
    reportDocument = new QtRPT;
    reportDocument->loadReport(fileName);
    reportDocument->recordCount.append(sqlDb->modelContent->rowCount());
    QObject::connect(reportDocument, SIGNAL(setValue(const int, const QString, QVariant&, const int)),
                     this, SLOT(setValue(const int, const QString, QVariant&, const int)));
    reportDocument->printExec();
}
void MainForm::setValue(const int recNo, const QString paramName, QVariant &paramValue, const int reportPage) {
    Q_UNUSED(reportPage);
    if (paramName == "title")
        paramValue = sqlDb->modelContent->record(recNo).value("colTitle").toString();
    if (paramName == "body")
        paramValue = sqlDb->modelContent->record(recNo).value("colBody").toString();
    if (paramName == "answer")
        paramValue = sqlDb->modelContent->record(recNo).value("colAnswer").toString();
}

//키입력을 감시해서 다른 행동을 하게 하기 위한 일종의 후킹함수
//한글입력후 엔터등을 눌렀을 때 캐럿이 사라지는 것을 막고자 포커스를 죽였다가 살린다.
//이 경우 올바른 해결책은 IME메시지를 받아 포커스를 조작하는 것인데 아직 못했다.
bool MainForm::eventFilter(QObject* obj, QEvent* event)
{
    if(obj == bodyWebView)
    {
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            int key = keyEvent->key();
            if(key == Qt::Key_Shift){
                return false;
            }else if(key == Qt::Key_Return||Qt::Key_Enter||Qt::Key_Space
                    ||Qt::Key_Insert||Qt::Key_Delete||Qt::Key_Home
                    ||Qt::Key_End||Qt::Key_PageUp||Qt::Key_PageDown
                    ||Qt::Key_Left||Qt::Key_Right||Qt::Key_Up||Qt::Key_Down)
            {
                bodyWebView->clearFocus();
                bodyWebView->setFocus();
                return false;
            }
        }else{
            return false;
        }
    }else{
        //pass the event on to the parent class
        return QWidget::eventFilter(obj, event);
    }
}
