#include "userprivileges.h"
#include "ui_userprivileges.h"
#include "adduserprivileges.h"
#include "userconfiguration.h"
#include "boxretrieval.h"
#include "activitylog.h"
#include "spiinterface.h"

UserPrivileges::UserPrivileges(QWidget *parent, QString user_) :
    QWidget(parent),
    ui(new Ui::UserPrivileges)
{
    ui->setupUi(this);

    user = user_;
    ui->userIDTextBrowser->setText(user_);

    updateUPriv();
}

UserPrivileges::~UserPrivileges()
{
    delete ui;
}

void UserPrivileges::updateUPriv()
{
    QListWidgetItem * sdbItems;
    int arraySize;

    sdbItems = dbi.getUserPrivileges(user, arraySize);
    for (int i = 0; i<arraySize; i++)
        ui->sdbListWidget->addItem(&sdbItems[i]);

    if(ui->sdbListWidget->count() == 0)
    {
        ui->deleteButton->setEnabled(false);
        ui->retrieveButton->setEnabled(false);
    }

    else
    {
        ui->deleteButton->setEnabled(true);
        ui->retrieveButton->setEnabled(true);
    }
}

void UserPrivileges::on_addButton_clicked()
{
    addUP = new AddUserPrivileges(0, user);
    addUP->showFullScreen();
    this->close();
}

void UserPrivileges::on_deleteButton_clicked()
{
    dbi.deletePrivilege(user, ui->sdbListWidget->currentItem()->text());
    QString privilegeRemoved = "SDB_" + ui->sdbListWidget->currentItem()->text() + "_removed";
    log->write(user, privilegeRemoved);
    ui->sdbListWidget->takeItem(ui->sdbListWidget->currentRow());

    if(ui->sdbListWidget->count() == 0)
    {
        ui->deleteButton->setEnabled(false);
        ui->retrieveButton->setEnabled(false);
    }
}

void UserPrivileges::on_backButton_clicked()
{
    uconf = new UserConfiguration();
    uconf->showFullScreen();
    this->close();
}

void UserPrivileges::on_retrieveButton_clicked()
{
    if(spi->checkStatus())
    {
        boxret = new BoxRetrieval(0, "upriv", user, ui->sdbListWidget->currentItem()->text());
        boxret->showFullScreen();
        this->close();
    }
}
