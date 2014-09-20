#include "hexdecodermanager.h"
#include "hexdecoder.h"
#include <QString>
#include <iostream>

HexdecoderManager::HexdecoderManager(QString rowLog, QStringList fieldTypes)
{
    RowLogContent=rowLog;
    this->fieldTypes=fieldTypes;
}

QStringList HexdecoderManager::splitRowLog()
{
    QStringList data;
    Hexdecoder decode;
    int offset=8;
    for(int i=0;i<fieldTypes.count();i++){
        QString data_type=fieldTypes.at(i);


        if(data_type.toStdString()=="int"){
            QString value="";
            for(int x=offset;x<offset+8;x++){
                value.append(RowLogContent.at(x));
            }
            offset+=8;
            data.append(QString::number(decode.Hextoint(value.toStdString())));
        }

        else if(data_type.toStdString()=="nchar"){
            QString value="";
            value.append(RowLogContent.at(offset));
            value.append(RowLogContent.at(offset+1));
            data.append(decode.Hextochar(value.toStdString()));
            offset+=2;

        }

        else if(data_type.toStdString()=="bigint" ){
            QString value="";
            for(int x=offset;x<offset+16;x++){
                value.append(RowLogContent.at(x));
            }
            data.append(QString::number(decode.Hextobigint(value.toStdString())));
            offset+=16;


        }

        else if(data_type.toStdString()=="tinyint"){
            QString value="";
            value.append(RowLogContent.at(offset));
            value.append(RowLogContent.at(offset+1));
            data.append(QString::number(decode.Hextotinyint(value.toStdString())));
            offset+=2;
        }
        else if(data_type.toStdString()=="money"){
            QString value="";
            for(int x=offset;x<offset+16;x++){
                value.append(RowLogContent.at(x));
            }
            data.append(decode.Hextomoney(value.toStdString()));
            offset+=16;


        }


    }
    return data;

}
