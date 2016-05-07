#ifndef ADDUSERPRIVILEGES_H
#define ADDUSERPRIVILEGES_H
#include "dbinterface.h"
#include <QWidget>

class UserPrivileges;
class ActivityLog;

namespace Ui {
class AddUserPrivileges;
}

class AddUserPrivileges : public QWidget
{
    Q_OBJECT

public:
    explicit AddUserPrivileges(QWidget *parent = 0, QString = "");
    ~AddUserPrivileges();

    void updateSDBUsage();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddUserPrivileges *ui;
    UserPrivileges* upriv;
    ActivityLog* log;
    QString userID;
    DBInterface dbi;
};

#endif // ADDUSERPRIVILEGES_H
