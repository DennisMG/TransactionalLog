#include "hexdecoder.h"
#include <QString>
#include <sstream>
#include <iostream>

using namespace std;
Hexdecoder::Hexdecoder()
{
}

QString Hexdecoder::Hextochar(string hexadecimal_input)
{
    int output;
    QString value;
    stringstream ss;
    ss<<hex<<hexadecimal_input.at(0);
    ss<<hex<<hexadecimal_input.at(1);
    ss>>output;
    value=(char)output;
    return value;

}


string Hexdecoder::Hextovarchar(string hexadecimal_input)
{
    string buffer="";
    string decodedString="";

    for(int i=0;i<hexadecimal_input.length();i+=2){
        buffer+=hexadecimal_input.at(i);
        buffer+=hexadecimal_input.at(i+1);
        decodedString+=Hextochar(buffer).toStdString();
        buffer="";

    }
    return decodedString;
}

void Hexdecoder::Hextodatetime()
{
}

void Hexdecoder::Hextosmalldatetime()
{
}

int Hexdecoder::Hextoint(string hexadecimal_input)
{
    unsigned int x;
    int output;
    stringstream ss;

    for(int i = hexadecimal_input.length(); i>0;i-=2){
        ss << hex << hexadecimal_input.at(i-2);
        ss << hex << hexadecimal_input.at(i-1);
    }

    ss >> x;
    output=static_cast<int>(x);
    return output;

}

long long int Hexdecoder::Hextobigint(string hexadecimal_input)
{
    //8 bytes
    unsigned long long int x;
    int output;
    stringstream ss;

    for(int i = hexadecimal_input.length(); i>0;i-=2){
        ss << hex << hexadecimal_input.at(i-2);
        ss << hex << hexadecimal_input.at(i-1);
    }

    ss >> x;
    return x;
}

int Hexdecoder::Hextotinyint(string hexadecimal_input)
{
    //1 byte
    unsigned short int x;
    int output;
    stringstream ss;
    ss << hex << hexadecimal_input.at(0);
    ss << hex << hexadecimal_input.at(1);
    ss >> x;
    cout<<x<<endl;
    output=x;
    return output;

}

void Hexdecoder::Hextodecimal()
{

}

QString Hexdecoder::Hextomoney(string hexadecimal_input)
{
    QString money=QString::number(Hextobigint(hexadecimal_input));
    money.insert(money.length()-4,".");
    return money;
}

void Hexdecoder::Hextofloat()
{
}

void Hexdecoder::Hextoreal()
{
}

void Hexdecoder::Hextonumeric()
{
}

void Hexdecoder::Hextobit()
{
}
