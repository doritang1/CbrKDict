//데이터베이스 생성 및 관리를 위한 엔진이다.
//updated Mar-22-2016

#ifndef CKDBENGINE_H
#define CKDBENGINE_H

#include <QtSql>
#include <QSqlTableModel>
#include <QDataWidgetMapper>

class CKDBEngine
{
public:
    CKDBEngine();
    ~CKDBEngine();

    //DB 연결함. DB파일의 이름과 DB타입을 문자열 참조자로 받는다.
    //dbType의 기본값은 QSQLITE이고,
    //fileName의 기본값은 ":memory:"이다.
    bool connectDb(const QString &dbType = "QSQLITE", const QString &fileName = ":memory:");

    //title 테이블의 데이터를 제공하는 모델
    QSqlTableModel *modelCategoryLevel1;
    QSqlTableModel *modelCategoryLevel2;
    QSqlTableModel *modelCategoryLevel3;

    QSqlTableModel *modelContent;
    QDataWidgetMapper *mapperContent;

private:
    //DB객체
    QSqlDatabase db;
};

#endif // CKDBENGINE_H
