#ifndef USERBOXACCESS_H
#define USERBOXACCESS_H

#include <QWidget>
#include <QSqlDatabase>
#include "dbinterface.h"

class Login;
class ActivityLog;

namespace Ui {
class UserBoxAccess;
}

class UserBoxAccess : public QWidget
{
    Q_OBJECT

public:
    explicit UserBoxAccess(QWidget *parent = 0, QSqlDatabase* db = NULL, QString = "");
    ~UserBoxAccess();
    void update();

private slots:
    void on_logOutButton_clicked();

private:
    Ui::UserBoxAccess *ui;
    QSqlDatabase* fv_db;
    ActivityLog* log;
    Login* login;
    QString currentUser;
    DBInterface dbi;
};

#endif // USERBOXACCESS_H
