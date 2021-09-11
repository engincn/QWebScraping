#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <fstream>

class parser
{
public:
    parser(std::string xmlName);
    void lineCounter();
    std::string readPart(int line, int startChar, int charLenght);
    std::string readRate(int line);

private:
    int lineCount;
    std::fstream xml;
};

#endif // PARSER_H
