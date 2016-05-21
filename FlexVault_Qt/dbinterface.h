#ifndef DBINTERFACE_H
#define DBINTERFACE_H

#include <QString>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QListWidgetItem>

class DBInterface
{
public:
QListWidgetItem* getColumnAsItems(QString table, QString column, int & retSize);
bool validateLogin(QString userID, QString password);
void writeUserToDb(QString userID, QString password);
void connectToDb(QSqlDatabase &fv_db);
void disconnectFromDb(QSqlDatabase &fv_db);
void assignPrivileges(QString, QString);
QListWidgetItem* getUserPrivileges(QString, int & retSize);
QString getUserID(QString);
bool checkBoxUsage(QString);
bool checkName(QString);
void deletePrivilege(QString userID, QString sdb);
void deleteUser(QString userID);
};

#endif // DBINTERFACE_H
