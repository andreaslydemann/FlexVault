#ifndef ADMINMAINMENU_H
#define ADMINMAINMENU_H

#include <QWidget>
#include "dbinterface.h"

class UserConfiguration;
class AdminBoxAccess;
class ActivityLog;
class Login;

namespace Ui {
class AdminMainMenu;
}

class AdminMainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMainMenu(QWidget *parent = 0);
    ~AdminMainMenu();

private slots:
    void on_usersButton_clicked();
    void on_logOutButton_clicked();
    void on_logButton_clicked();
    void on_sdbButton_clicked();

private:
    Ui::AdminMainMenu *ui;
    UserConfiguration *uconf;
    AdminBoxAccess* aba;
    ActivityLog *log;
    Login* login;
};

#endif // ADMINMAINMENU_H
