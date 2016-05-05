#include "userprivileges.h"
#include "ui_userprivileges.h"
#include "adduserprivileges.h"
#include "userconfiguration.h"

UserPrivileges::UserPrivileges(QWidget *parent, QString user_, QSqlDatabase* db) :
    QWidget(parent),
    ui(new Ui::UserPrivileges)
{
    ui->setupUi(this);

    user = user_;
    ui->userIDTextBrowser->setText(user_);
    fv_db = db;

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
}

void UserPrivileges::on_addButton_clicked()
{
    addUP = new AddUserPrivileges(0, user);
    this->close();
    addUP->show(); // change to showFullScreen() for BeagleBone
}

void UserPrivileges::on_deleteButton_clicked()
{
    dbi.deletePrivilege(user, ui->sdbListWidget->currentItem()->text());
    ui->sdbListWidget->takeItem(ui->sdbListWidget->currentRow());
}

void UserPrivileges::on_backButton_clicked()
{
    uConf = new UserConfiguration(0, fv_db);
    uConf->show();
    this->close();
}
