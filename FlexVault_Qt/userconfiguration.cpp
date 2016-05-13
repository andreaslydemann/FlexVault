#include "userconfiguration.h"
#include "ui_userconfiguration.h"
#include "usercreationdialog.h"
#include "userprivileges.h"
#include "adminmainmenu.h"
#include "activitylog.h"

UserConfiguration::UserConfiguration(QWidget *parent) :
    QWidget(parent),
   ui(new Ui::UserConfiguration)
{
    ui->setupUi(this);

    updateUConf();
}

UserConfiguration::~UserConfiguration()
{
    delete ui;
}

void UserConfiguration::on_createButton_clicked()
{
    qDebug() << "create button clicked..\n";

    ucd = new UserCreationDialog(this);
    ucd->move(0, 0);
    ucd->show();
}

void UserConfiguration::updateUConf()
{
    QListWidgetItem * userItems;

    // Erase list
    int count = ui->userListWidget->count();
    for (int i = 0; i<count; i++)
    {
        int a = 0;
        ui->userListWidget->takeItem(a);
        a++;
    }
    //create list
    int arraySize;
    userItems = dbi.getColumnAsItems("users", "name", arraySize);
    for (int i = 0; i<arraySize; i++)
        ui->userListWidget->addItem(&userItems[i]);

    if(ui->userListWidget->count() == 0)
    {
        ui->privilegesButton->setEnabled(false);
        ui->deleteButton->setEnabled(false);
    }

    else
    {
        ui->privilegesButton->setEnabled(true);
        ui->deleteButton->setEnabled(true);
    }
}

void UserConfiguration::on_privilegesButton_clicked()
{
    upriv = new UserPrivileges(NULL, ui->userListWidget->currentItem()->text());
    upriv->move(0, 0);
    upriv->showFullScreen(); // change to showFullScreen() for BeagleBone
    this->close();
}

void UserConfiguration::on_deleteButton_clicked()
{
    dbi.deleteUser(ui->userListWidget->currentItem()->text());
    log->write(ui->userListWidget->currentItem()->text(), "Deleted");
    ui->userListWidget->takeItem(ui->userListWidget->currentRow());

    if(ui->userListWidget->count() == 0)
    {
        ui->privilegesButton->setEnabled(false);
        ui->deleteButton->setEnabled(false);
    }

    else
    {
        ui->privilegesButton->setEnabled(true);
        ui->deleteButton->setEnabled(true);
    }
}

void UserConfiguration::on_backButton_clicked()
{
    amm = new AdminMainMenu();
    amm->move(0, 0);
    amm->showFullScreen(); // change to showFullScreen() for BeagleBone
    this->close();
}
