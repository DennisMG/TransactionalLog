#include "sqlserverconnectionmanager.h"
#include <QtSql>
#include <iostream>

using namespace std;

SqlServerConnectionManager::SqlServerConnectionManager()
{

}

void SqlServerConnectionManager::InitializeConnection()
{
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("Driver={SQL Server};Server=WINDOWS-59MVL0E;Database=DB_Test1;");
        db.setUserName("Testing");
        db.setPassword("123");
        if(!db.open()){
            db.close();
        }else{

            QSqlQuery query("SELECT Numero FROM Table_2");
            while (query.next())
            {

                  QString country = query.value(0).toString();
            }
        }
}

QStringList SqlServerConnectionManager::getDBTableList()
{
    QSqlQuery qry;
    QStringList allTables;

    qry.exec("select name from sysobjects where type='U'");
    while (qry.next())
    {
        allTables.append(qry.value(0).toString());
    }

    return allTables;

}

QStringList SqlServerConnectionManager::getDBFieldList(QString Table_Name)
{
    QSqlQuery qry;
    QStringList allFields;
    tableTypes.clear();

    qry.exec(QString("Select column_name,data_type from information_schema.columns where TABLE_NAME = '").append(Table_Name).append("'"));
    while(qry.next()){
        allFields.append(qry.value(0).toString());
        tableTypes.append(qry.value(1).toString());
    }
    return allFields;


}

QStringList SqlServerConnectionManager::getDBTableTypes()
{
    return tableTypes;
}

QStringList SqlServerConnectionManager::getRowLogContent(QString Table_Name)
{
    QSqlQuery qry;
    QByteArray rowlog;
    QStringList rowloglist;
    qry.exec(QString("SELECT [AllocUnitName], [rowlog contents 0], Operation FROM sys.fn_dblog (NULL, NULL) WHERE operation IN ('LOP_DELETE_ROWS') and AllocUnitName='dbo.").append(Table_Name).append("'; "));
    while(qry.next()){
        rowloglist.append(qry.value(1).toByteArray().toHex());
        cout<<rowloglist.at(0).count()<<endl;
        cout<<rowloglist.count()<<endl;

    }
    if(rowloglist.count()>0)
        //cout<<rowloglist.at(2).toStdString()<<endl;

    return rowloglist;
}
