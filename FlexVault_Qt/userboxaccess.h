#ifndef USERBOXACCESS_H
#define USERBOXACCESS_H

#include <QWidget>
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
    explicit UserBoxAccess(QWidget *parent = 0, QString = "");
    ~UserBoxAccess();
    void update();

private slots:
    void on_logOutButton_clicked();

private:
    Ui::UserBoxAccess *ui;
    ActivityLog* log;
    Login* login;
    QString currentUser;
    DBInterface dbi;
};

#endif // USERBOXACCESS_H
