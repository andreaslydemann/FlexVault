#include "dbinterface.h"
#include "inactivityfilter.h"
#include "login.h"
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication fv(argc, argv);
    fv.setQuitOnLastWindowClosed(false);

    InactivityFilter filter;
    fv.installEventFilter(&filter);

    QSqlDatabase* fv_db = new QSqlDatabase; // allocate QSqlDatabase object
    DBInterface dbi;
    dbi.connectToDb(*fv_db);

    Login login(0);
    login.showFullScreen();

    return fv.exec();
}

