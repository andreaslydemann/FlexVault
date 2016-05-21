#ifndef USERPRIVILEGES_H
#define USERPRIVILEGES_H

#include <QWidget>
#include "dbinterface.h"

class AddUserPrivileges;
class UserConfiguration;
class BoxRetrieval;
class ActivityLog;

namespace Ui {
class UserPrivileges;
}

class UserPrivileges : public QWidget
{
    Q_OBJECT

public:
    explicit UserPrivileges(QWidget *parent = 0, QString = "");
    ~UserPrivileges();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_backButton_clicked();
    void on_retrieveButton_clicked();
    void updateUPriv();

private:
    Ui::UserPrivileges* ui;
    AddUserPrivileges* addUP;
    UserConfiguration* uconf;
    BoxRetrieval* boxret;
    ActivityLog* log;
    DBInterface dbi;
    QString user;

signals:
    void addButton_clicked();
};

#endif // USERPRIVILEGES_H
