#ifndef SPIINTERFACE_H
#define SPIINTERFACE_H

#include <QString>
#include <QDebug>
#include <cstdio>
#include <fcntl.h>
#include <unistd.h>

class SPIInterface
{
public:
    SPIInterface();
    int writeToFV(QString*, unsigned int*);
    int readFromFV();
    bool checkWeight();
    void returnSDB(QString);
    void retrieveSDB(QString);
};

#endif // SPIINTERFACE_H
