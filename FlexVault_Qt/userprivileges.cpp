#include "userprivileges.h"
#include "ui_userprivileges.h"
#include "adduserprivileges.h"
#include "userconfiguration.h"
#include "boxretrieval.h"
#include "activitylog.h"

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

    // Erase list
    int count = ui->sdbListWidget->count();

    for (int i = 0; i<count; i++)
    {
        int a = 0;
        ui->sdbListWidget->takeItem(a);
        a++;
    }

    //create list
    int arraySize;
    sdbItems = dbi.getUserPrivileges(user, arraySize);
    for (int i = 0; i<arraySize; i++)
        ui->sdbListWidget->addItem(&sdbItems[i]);

    if(ui->sdbListWidget->count() == 0)
        ui->deleteButton->setEnabled(false);

    else
        ui->deleteButton->setEnabled(true);
}

void UserPrivileges::on_addButton_clicked()
{
    addUP = new AddUserPrivileges(0, user);
    addUP->move(0, 0);
    this->close();
    addUP->show(); // change to showFullScreen() for BeagleBone
}

void UserPrivileges::on_deleteButton_clicked()
{
    dbi.deletePrivilege(user, ui->sdbListWidget->currentItem()->text());
    QString privilegeRemoved = "SDB_" + ui->sdbListWidget->currentItem()->text() + "_removed";
    log->write(user, privilegeRemoved);
    ui->sdbListWidget->takeItem(ui->sdbListWidget->currentRow());

    if(ui->sdbListWidget->count() == 0)
        ui->deleteButton->setEnabled(false);
}

void UserPrivileges::on_backButton_clicked()
{
    uconf = new UserConfiguration();
    uconf->move(0, 0);
    uconf->show();
    this->close();
}

void UserPrivileges::on_retrieveButton_clicked()
{
    boxret = new BoxRetrieval(0, "upriv", user);
    boxret->move(0, 0);
    boxret->show();

    this->close();
}
