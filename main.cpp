#include <QtGui/QApplication>
#include "mainwindow.h"
#include "hexdecoder.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Hexdecoder trial;


    trial.Hextoint("39300000");//12345


    trial.Hextovarchar("444550543031");


    trial.Hextochar("46");//caracter: !
    cout<<"tiny int: ";
    trial.Hextotinyint("6f");//valor: 111
    cout<<"Big int: ";
    cout<<trial.Hextobigint("383a0f86487000")<<endl;
    w.show();
    
    return a.exec();
}
