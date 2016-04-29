#ifndef ADMINMAINMENU_H
#define ADMINMAINMENU_H

#include <QWidget>
#include "dbinterface.h"

class UserConfiguration;
class Login;

namespace Ui {
class AdminMainMenu;
}

class AdminMainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit AdminMainMenu(QWidget *parent = 0, QSqlDatabase* = NULL);
    ~AdminMainMenu();

private slots:
    void on_usersButton_clicked();

    void on_logOutButton_clicked();

private:
    Ui::AdminMainMenu *ui;
    UserConfiguration *uconf;
    QSqlDatabase* fv_db;
    Login* login;
};

#endif // ADMINMAINMENU_H
