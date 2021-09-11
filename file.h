#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QTextStream>

class file
{
public:
    file();
    void writeFile(QString str);

private:
    QFile *xml;

};

#endif // FILE_H
