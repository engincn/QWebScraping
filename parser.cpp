#include "parser.h"

parser::parser(std::string xmlName)
{
    lineCount = 1;
    xml.open(xmlName,std::ios::in);
}

void parser::lineCounter()
{
    std::string temp;
    xml.seekg(0,std::ios::beg);
    std::getline(xml, temp);

    while(!xml.eof())
    {
        std::getline(xml, temp);
        lineCount++;
    }
    xml.clear();
    xml.seekg(0,std::ios::beg);

}

std::string parser::readPart(int line, int startChar, int charLenght)
{
    std::string ret;
    std::string tempLine;
    xml.seekg(0,std::ios::beg);
    for( int i = 1; i <= line; i++ )
    {
        std::getline(xml,tempLine);
    }

    for(int j = 0; j < charLenght; j++)
    {
        ret = ret + tempLine[ j+startChar ];
    }

    return ret;
}

std::string parser::readRate(int line)
{
    std::string ret;
    std::string tempLine;
    xml.seekg(0,std::ios::beg);
    for( int i = 1; i <= line; i++ )
    {
        std::getline(xml,tempLine);
    }
    int i = 48;
    while( tempLine[i] != '%' )
    {
        ret = ret + tempLine[i];
        i++;
    }
    ret = ret + '%';
    return ret;
}
