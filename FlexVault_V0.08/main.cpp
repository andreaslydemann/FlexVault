#include "dbinterface.h"
#include "login.h"
#include <QApplication>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase* fv_db = new QSqlDatabase; //Allocate QSqlDatabase object

    DBInterface dbi;
    dbi.connectToDb(*fv_db);

    Login login(0, fv_db);

    QPalette loginPalette = login.palette();
    loginPalette.setBrush( QPalette::Normal, QPalette::Window, QBrush( Qt::yellow ) );
    login.setPalette(loginPalette);

    login.show(); // change to showFullScreen() for BeagleBone

    return a.exec();
}
