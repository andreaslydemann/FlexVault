#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

#include "dbinterface.h"

class AdminMainMenu;
class LoginFailedDialog;
class ActivityLog;
class UserBoxAccess;

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    bool eventFilter(QObject* object, QEvent* event);

public slots:
    void on_loginButton_clicked();
    void lineEdit_textChanged();

private:
    Ui::Login *ui;
    AdminMainMenu *amm;
    LoginFailedDialog *lfd;
    DBInterface dbi;
    ActivityLog* log;
    UserBoxAccess* uba;

signals:
    void loginButton_clicked();
    void textChanged(const QString &);
};

#endif // LOGIN_H
