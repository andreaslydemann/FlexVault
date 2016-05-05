#include "userboxaccess.h"
#include "ui_userboxaccess.h"
#include "activitylog.h"
#include "login.h"

UserBoxAccess::UserBoxAccess(QWidget *parent, QSqlDatabase* db, QString user) :
    QWidget(parent),
    ui(new Ui::UserBoxAccess)
{
    currentUser = user;
    fv_db = db;
    ui->setupUi(this);

    update();
}

UserBoxAccess::~UserBoxAccess()
{
    delete ui;
}

void UserBoxAccess::on_logOutButton_clicked()
{
    log->write(currentUser, "Log_Out");
    login = new Login(0, fv_db);
    login->show();
    this->close();
}

void UserBoxAccess::update()
{
    QListWidgetItem * sdbItems;

    // Erase list
    int count = ui->boxListWidget->count();

    for (int i = 0; i<count; i++)
    {
        int a = 0;
        ui->boxListWidget->takeItem(a);
        a++;
    }

    //create list
    int arraySize;
    sdbItems = dbi.getUserPrivileges(currentUser, arraySize);
    for (int i = 0; i<arraySize; i++)
        ui->boxListWidget->addItem(&sdbItems[i]);
}
