#ifndef USERCONFIGURATION_H
#define USERCONFIGURATION_H

#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

#include "dbinterface.h"

class UserCreationDialog;
class UserPrivileges;
class AdminMainMenu;
class ActivityLog;

namespace Ui {
class UserConfiguration;
}

class UserConfiguration : public QWidget
{
    Q_OBJECT

public:
    explicit UserConfiguration(QWidget *parent = 0);
    ~UserConfiguration();

public slots:
    void updateUConf();

private slots:
    void on_createButton_clicked();

    void on_privilegesButton_clicked();

    void on_deleteButton_clicked();

    void on_backButton_clicked();

private:
    Ui::UserConfiguration *ui;
    UserCreationDialog *ucd;
    AdminMainMenu* amm;
    UserPrivileges* upriv;
    ActivityLog* log;
    DBInterface dbi;

signals:
    void privilegesButton_clicked();

};

#endif // USERCONFIGURATION_H
