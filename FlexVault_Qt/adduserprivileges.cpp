#include "adduserprivileges.h"
#include "ui_adduserprivileges.h"
#include "userprivileges.h"
#include "activitylog.h"

AddUserPrivileges::AddUserPrivileges(QWidget *parent, QString userID_) :
    QWidget(parent),
    ui(new Ui::AddUserPrivileges)
{
    ui->setupUi(this);
    userID = userID_;

    ui->msg1Label->setWordWrap(true);

    updateSDBUsage();
}

AddUserPrivileges::~AddUserPrivileges()
{
    delete ui;
}

void AddUserPrivileges::updateSDBUsage()
{
    for(int i = 1; i <= 20; i++)
        ui->sdbListWidget->addItem("SAFE DEPOSIT BOX " + QString::number(i));

    int a = 0;

    for(int i = 1; i <= 20; i++)
    {
        if(dbi.checkBoxUsage(QString::number(i)))
            ui->sdbListWidget->item(a)->setForeground(QBrush(QColor(Qt::red)));

        else
            ui->sdbListWidget->item(a)->setForeground(QBrush(QColor(Qt::green)));

        a++;
    }
}

void AddUserPrivileges::on_buttonBox_accepted()
{
    dbi.assignPrivileges(userID, ui->sdbListWidget->currentItem()->text().mid(17,2));
    QString privilegeAdded = "SDB_" + ui->sdbListWidget->currentItem()->text().mid(17,2) + "_added";
    log->write(userID, privilegeAdded);

    upriv = new UserPrivileges(0, userID);
    upriv->move(0, 0);
    upriv->show();
    this->close();
}

void AddUserPrivileges::on_buttonBox_rejected()
{
    upriv = new UserPrivileges(0, userID);
    upriv->move(0, 0);
    upriv->show();
    this->close();
}
