#include "dbinterface.h"

QListWidgetItem* DBInterface::getColumnAsItems(QString table, QString column, int &retSize)
{
    QListWidgetItem* items;
    {
        QSqlQuery qry;
        QString userID;

        qry.exec("SELECT " + column + " FROM " + table);

        int count = 0;
        while(qry.next())
        {
            count++;
        }
        items = new QListWidgetItem[count];
        qry.exec("SELECT " + column + " FROM " +table);

        for (int i = 0; qry.next(); i++)
        {
            userID = qry.value(0).toString();
            QListWidgetItem temp(userID);
            items[i] =temp;
        }
        retSize=count;
    }

    return items;
}

bool DBInterface::validateLogin(QString name, QString password)
{
    QSqlQuery qry;

    qry.exec("SELECT name FROM users");

    for (int i = 0; qry.next(); i++)
    {
        if(name == qry.value(0).toString())
        {
            qry.exec("SELECT password FROM users");

            for (int j = 0; qry.next(); j++)
            {
                if(i == j && password == qry.value(0).toString())
                    return true;

                if(j > i)
                    break;
            }
        }
    }

    return false;
}

void DBInterface::writeUserToDb(QString name, QString password)
{
    QSqlQuery qry;
    qry.exec("insert into users(name, password) values('" + name + "','" + password + "')");
}

void DBInterface::connectToDb(QSqlDatabase &fv_db)
{

    fv_db = QSqlDatabase::addDatabase("QSQLITE"); //use SQLite

    //set path
    fv_db.setDatabaseName("/home/stud/FV/FlexVault/FlexVault_Qt/fv.db");
    //fv_db.setDatabaseName("/home/root/fv.db");

    if (!fv_db.open())
    {
        qDebug() << "FAILED TO OPEN DATABASE!\n";
    }
    else
    {
        qDebug()<< "Connection acquired...\n";
    }
}

void DBInterface::disconnectFromDb(QSqlDatabase &fv_db)
{
    fv_db.close();
    fv_db=QSqlDatabase();
    QSqlDatabase::removeDatabase(fv_db.connectionName());
}

void DBInterface::assignPrivileges(QString name, QString sdb)
{
    QSqlQuery qry;
    qry.exec("insert into privileges(userID, boxID) values('" + getUserID(name) + "','" + sdb + "');");
}

bool DBInterface::checkBoxUsage(QString sdb)
{
    QSqlQuery qry;

    qry.exec("SELECT boxID FROM privileges");

    for (int i = 0; qry.next(); i++)
    {
        if(sdb == qry.value(0).toString())
            return true;
    }

    return false;
}

bool DBInterface::checkName(QString name)
{
    QSqlQuery qry;

    qry.exec("SELECT name FROM users");

    for (int i = 0; qry.next(); i++)
    {
        if(name == qry.value(0).toString())
            return true;
    }

    return false;
}

QListWidgetItem* DBInterface::getUserPrivileges(QString name, int &retSize)
{
    QSqlQuery qry;
    QListWidgetItem* items;
    QString boxID = 0;

    qry.exec("SELECT boxID FROM privileges where userID = '" + getUserID(name) + "';");

    int count = 0;
    while(qry.next())
    {
        count++;
    }

    items = new QListWidgetItem[count];
    qry.exec("SELECT boxID FROM privileges where userID = '" + getUserID(name) + "';");

    for (int i = 0; qry.next(); i++)
    {
        boxID = qry.value(0).toString();
        QListWidgetItem temp(boxID);
        items[i] = temp;
    }

    retSize = count;

    return items;
}

QString DBInterface::getUserID(QString name)
{
    QSqlQuery qry;
    QString userID;

    qry.exec("SELECT userID FROM users WHERE name = '" + name + "';");

    if (qry.next())
    {
    QSqlRecord record = qry.record();
    userID = qry.value(record.indexOf("userID")).toString();
    }

    return userID;
}

void DBInterface::deletePrivilege(QString name, QString sdb)
{
    QSqlQuery qry;

    qry.exec("DELETE FROM privileges WHERE userID = '" + getUserID(name) + "' AND boxID = '" + sdb + "';");
}

void DBInterface::deleteUser(QString name)
{
    QSqlQuery qry;

    qry.exec("DELETE FROM privileges WHERE userID = '" + getUserID(name) + "';");
    qry.exec("DELETE FROM users WHERE userID = '" + getUserID(name) + "';");
}
