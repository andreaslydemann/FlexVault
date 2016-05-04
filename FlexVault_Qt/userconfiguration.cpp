#include "userconfiguration.h"
#include "ui_userconfiguration.h"
#include "usercreationdialog.h"
#include "userprivileges.h"
#include "adminmainmenu.h"

UserConfiguration::UserConfiguration(QWidget *parent, QSqlDatabase* db) :
    QWidget(parent),
   ui(new Ui::UserConfiguration)
{
    fv_db = db;

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
}

void UserConfiguration::on_privilegesButton_clicked()
{
    upriv = new UserPrivileges(NULL, ui->userListWidget->currentItem()->text(), fv_db);
    upriv->show(); // change to showFullScreen() for BeagleBone
    this->close();

    //dbi.createUserPTable(ui->userListWidget->currentItem()->text());
}

void UserConfiguration::on_deleteButton_clicked()
{
    dbi.deleteUser(ui->userListWidget->currentItem()->text());
    ui->userListWidget->takeItem(ui->userListWidget->currentRow());
}

void UserConfiguration::on_backButton_clicked()
{
    amm = new AdminMainMenu(0, fv_db);
    amm->show(); // change to showFullScreen() for BeagleBone
    this->close();
}
