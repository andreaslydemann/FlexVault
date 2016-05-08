#include "dbinterface.h"
#include "login.h"
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase* fv_db = new QSqlDatabase; // allocate QSqlDatabase object
    DBInterface dbi;
    dbi.connectToDb(*fv_db);

    Login login(0);
    login.move(0, 0);
    login.show(); // change to showFullScreen() for BeagleBone

    return a.exec();
}
