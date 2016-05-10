#ifndef SPIINTERFACE_H
#define SPIINTERFACE_H

#include <QString>
#include <QProcess>

class SPIInterface
{
public:
    SPIInterface();
    void write(QString, QString);

signals:

public slots:
};

#endif // SPIINTERFACE_H
