#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

#include "dbinterface.h"

class AdminMainMenu;
class LoginFailedDialog;

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0, QSqlDatabase* = NULL);
    ~Login();

private slots:
    void on_loginButton_clicked();
    void lineEdit_textChanged();

private:
    Ui::Login *ui;
    AdminMainMenu *amm;
    LoginFailedDialog *lfd;
    QSqlDatabase* fv_db; //flex vault database pointer
    DBInterface dbi;

signals:
    void loginButton_clicked();
    void textChanged(const QString &);
};

#endif // LOGIN_H
