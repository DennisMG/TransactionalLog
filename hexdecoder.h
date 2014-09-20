#ifndef HEXDECODER_H
#define HEXDECODER_H
#include <string>
#include <QString>
using namespace std;
class Hexdecoder
{
public:
    Hexdecoder();
    QString Hextochar(string hexadecimal_input);
    string Hextovarchar(string hexadecimal_input);
    void Hextodatetime();
    void Hextosmalldatetime();
    int Hextoint(string hexadecimal_input);
    long long int Hextobigint(string hexadecimal_input);
    int Hextotinyint(string hexadecimal_input);
    void Hextodecimal();
    QString Hextomoney(string hexadecimal_input);
    void Hextofloat();
    void Hextoreal();
    void Hextonumeric();
    void Hextobit();
};

#endif // HEXDECODER_H
