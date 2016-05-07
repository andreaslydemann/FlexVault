#include "dbinterface.h"
#include "login.h"
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase* fv_db = new QSqlDatabase; //Allocate QSqlDatabase object

    DBInterface dbi;
    dbi.connectToDb(*fv_db);

    Login login(0);

    //QPalette loginPalette = login.palette();
    //loginPalette.setBrush( QPalette::Normal, QPalette::Window, QBrush( Qt::yellow ) );
    //login.setPalette(loginPalette);

    login.move(0, 0);
    login.show(); // change to showFullScreen() for BeagleBone

    return a.exec();
}
