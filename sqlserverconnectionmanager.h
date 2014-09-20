#ifndef SQLSERVERCONNECTIONMANAGER_H
#define SQLSERVERCONNECTIONMANAGER_H
#include <QtSql>
#include <iostream>
#include <string>
using namespace std;
class SqlServerConnectionManager
{
public:
    SqlServerConnectionManager();
    void InitializeConnection();
    QStringList getDBTableList();
    QStringList getDBFieldList(QString Table_Name);
    QStringList getDBTableTypes();
    QStringList getRowLogContent(QString Table_Name);


private:
    QStringList tableTypes;
    QSqlDatabase db;
};

#endif // SQLSERVERCONNECTIONMANAGER_H
