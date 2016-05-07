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
    //qry.exec("insert into userlist(userID, password) values('" + userID + "','" + password + "')");
}

void DBInterface::connectToDb(QSqlDatabase &fv_db)
{

    fv_db = QSqlDatabase::addDatabase("QSQLITE"); //use SQLite

    //set path
    fv_db.setDatabaseName("/home/stud/FV/FlexVault/fv.db");

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

//void DBInterface::createUserPTable(QString userID)
//{
//    QSqlQuery qry;

//    qry.exec("CREATE TABLE " + userID + "(post_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, box_access INTEGER NOT NULL);");
//}

void DBInterface::assignPrivileges(QString name, QString sdb)
{
    qDebug() << "userid:" << getUserID(name);
    qDebug() << "sdb:" << sdb;
    QSqlQuery qry;
    qry.exec("insert into privileges(userID, boxID) values('" + getUserID(name) + "','" + sdb + "');");

    //qry.exec("insert into " + name + "(box_access) values(" + sdb + ");");
}

//int DBInterface::getUserCount(QString sdb)
//{
//    QSqlQuery qry;
//    int count;

//    qry.exec("SELECT user_count FROM safedb WHERE post_id = '" + sdb + "';");

//    if (qry.next ())
//    {
//    QSqlRecord record = qry.record();
//    count = qry.value(record.indexOf("user_count")).toInt();
//    }

//    return count;
//}

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

    qDebug() << name;

    qry.exec("SELECT userID FROM users WHERE name = '" + name + "';");

    if (qry.next())
    {
    QSqlRecord record = qry.record();
    userID = qry.value(record.indexOf("userID")).toString();
    }

    qDebug() << userID;

    return userID;
}

//void DBInterface::incUserCount(QString sdb)
//{
//    QSqlQuery qry;
//    qry.exec("UPDATE safedb SET user_count = (user_count + 1) WHERE post_id = '" + sdb + "';");
//}

//void DBInterface::decUserCount(QString sdb)
//{
//    QSqlQuery qry;
//    qry.exec("UPDATE safedb SET user_count = (user_count - 1) WHERE post_id = '" + sdb + "';");
//    // husk at kalde med .mid(17,2)
//}

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

//void DBInterface::resetSDB()
//{
//    QSqlQuery qry;
//    for(int i = 1; i <= 20; i++)
//        qry.exec("UPDATE safedb SET user_count = '0' WHERE post_id = '" + QString::number(i) + "';");

//    for(int i = 1; qry.next(); i++)
//        qry.exec("DROP TABLE " + getUserID(i) + ";");
//}
