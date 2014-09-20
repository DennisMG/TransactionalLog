#ifndef HEXDECODERMANAGER_H
#define HEXDECODERMANAGER_H
#include <QString>
#include <QStringList>
using namespace std;
class HexdecoderManager
{
public:
    HexdecoderManager(QString rowLog,QStringList fieldTypes);
    QStringList splitRowLog();


private:
    QString RowLogContent;
    QStringList fieldTypes;

};

#endif // HEXDECODERMANAGER_H
