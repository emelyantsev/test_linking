#include <QCoreApplication>
#include <iostream>

#include "dynlib.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    QString s("This string is created just for test purpose.");

    s = oddUpper(s);

    std::cout << s.toStdString() << std::endl;

    //return a.exec();
    return 0;
}
