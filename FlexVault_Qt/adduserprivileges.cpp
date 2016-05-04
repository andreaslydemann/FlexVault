#include "adduserprivileges.h"
#include "ui_adduserprivileges.h"
#include "userprivileges.h"

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
        qDebug() << dbi.checkBoxUsage(QString::number(i));
        if(dbi.checkBoxUsage(QString::number(i)))
            ui->sdbListWidget->item(a)->setForeground(QBrush(QColor(Qt::red)));

        else
            ui->sdbListWidget->item(a)->setForeground(QBrush(QColor(Qt::green)));

        a++;
    }
}

void AddUserPrivileges::on_buttonBox_accepted()
{
    //dbi.incUserCount(ui->sdbListWidget->currentItem()->text().mid(17,2));

    dbi.assignPrivileges(userID, ui->sdbListWidget->currentItem()->text().mid(17,2));

    uPriv = new UserPrivileges(0, userID);
    uPriv->show();
    this->close();
}

void AddUserPrivileges::on_buttonBox_rejected()
{
    uPriv = new UserPrivileges(0, userID);
    uPriv->show();
    this->close();
}
