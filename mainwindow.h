#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sqlserverconnectionmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
    void on_pushButton_clicked();

private slots:
    void on_pushButton_2_clicked();

    void on_DBTableList_clicked(const QModelIndex &index);

    void on_dataRowLogContent_clicked(const QModelIndex &index);

private:
    void connectSQLServer();
    void connectToSQLServer();
    void setdataRowLogContent(QString tableName);
    SqlServerConnectionManager db;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
