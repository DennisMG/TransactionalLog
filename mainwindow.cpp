#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sqlserverconnectionmanager.h"
#include <QStringListModel>
#include "hexdecodermanager.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectToSQLServer()
{

}

void MainWindow::setdataRowLogContent(QString tableName)
{
    QStringList rowLogContent=db.getRowLogContent(tableName);
    ui->dataRowLogContent->setColumnCount(1);
    ui->dataRowLogContent->horizontalHeader()->setStretchLastSection(true);
    ui->dataRowLogContent->setHorizontalHeaderLabels(QStringList("RowLog Contents 0"));
    ui->dataRowLogContent->setRowCount(rowLogContent.count());

    for(int i=0;i<rowLogContent.count();i++){
        QTableWidgetItem *cell = new QTableWidgetItem();
        cell->setText(rowLogContent.at(i));
        ui->dataRowLogContent->setItem(i,0,cell);



    }


}

void MainWindow::on_pushButton_clicked()
{
       connectSQLServer();
}

void MainWindow::connectSQLServer()
{
    db.InitializeConnection();
    QStringList TablesFromDB=db.getDBTableList();
    QStringListModel *listModel = new QStringListModel(TablesFromDB, NULL);
    ui->DBTableList->setModel(listModel);


}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_DBTableList_clicked(const QModelIndex &index)
{
    QString tableName = index.data().toString();
    QStringList fields;
    fields = db.getDBFieldList(tableName);
    ui->dataTableWidget->setColumnCount(fields.count());
    ui->dataTableWidget->setHorizontalHeaderLabels(fields);
    setdataRowLogContent(tableName);


}

void MainWindow::on_dataRowLogContent_clicked(const QModelIndex &index)
{
    QString rowLogSelected = index.data().toString();
    ui->dataTableWidget->setRowCount(1);
    cout<<rowLogSelected.toStdString()<<endl;
    HexdecoderManager *decode=new HexdecoderManager(rowLogSelected,db.getDBTableTypes());
    QStringList list = decode->splitRowLog();

    for(int i=0;i<list.count();i++){
        QTableWidgetItem *cell = new QTableWidgetItem();
        cell->setText(list.at(i));
        ui->dataTableWidget->setItem(0,i,cell);

    }


}
