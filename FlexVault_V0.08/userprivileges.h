#ifndef USERPRIVILEGES_H
#define USERPRIVILEGES_H

#include <QWidget>
#include "dbinterface.h"

class AddUserPrivileges;
class UserConfiguration;

namespace Ui {
class UserPrivileges;
}

class UserPrivileges : public QWidget
{
    Q_OBJECT

public:
    explicit UserPrivileges(QWidget *parent = 0, QString = "", QSqlDatabase * = NULL);
    ~UserPrivileges();

public slots:
    void updateUPriv(QString);

private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_backButton_clicked();

private:
    Ui::UserPrivileges* ui;
    AddUserPrivileges* addUP;
    UserConfiguration* uConf;
    QString userID;
    DBInterface dbi;
    QSqlDatabase* fv_db;

signals:
    void addButton_clicked();
};

#endif // USERPRIVILEGES_H
