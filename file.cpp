#include "file.h"

file::file()
{
    xml = new QFile("out.xml");
}

void file::writeFile(QString str)
{
    xml->open(QIODevice::WriteOnly);
    QTextStream out(xml);
    out << str;
}
