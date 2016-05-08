#ifndef USERBOXACCESS_H
#define USERBOXACCESS_H

#include <QWidget>
#include "dbinterface.h"

class Login;
class ActivityLog;
class BoxRetrieval;

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

    void on_retrieveButton_clicked();

private:
    Ui::UserBoxAccess *ui;
    ActivityLog* log;
    Login* login;
    QString user;
    BoxRetrieval* boxret;
    DBInterface dbi;
};

#endif // USERBOXACCESS_H
