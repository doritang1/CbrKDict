#include "ckdbengine.h"
#include <QMessageBox>

CKDBEngine::CKDBEngine()
{

}

//DB에 연결, 기본값이 있으므로 인자가 지정되지 않으면 기본값으로 InMemory DB를 받음
bool CKDBEngine::connectDb(const QString &dbType, const QString &fileName)
{
    db = QSqlDatabase::addDatabase(dbType);
    db.setDatabaseName(fileName);
    if(!db.open()){
        return false;
    }

     modelCategoryLevel1 = new QSqlTableModel();
     modelCategoryLevel1->setTable("tblCategoryLevel1");
     modelCategoryLevel1->setSort(1,Qt::AscendingOrder);
     modelCategoryLevel1->select();//첫번째 리스트뷰만 채운다.

     modelCategoryLevel2 = new QSqlTableModel();
     modelCategoryLevel2->setTable("tblCategoryLevel2");
     modelCategoryLevel2->setSort(1,Qt::AscendingOrder);

     modelCategoryLevel3 = new QSqlTableModel();
     modelCategoryLevel3->setTable("tblCategoryLevel3");
     modelCategoryLevel3->setSort(1,Qt::AscendingOrder);

     return true;
}
