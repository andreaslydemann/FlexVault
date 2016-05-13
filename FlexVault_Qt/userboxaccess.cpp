#include "userboxaccess.h"
#include "ui_userboxaccess.h"
#include "boxretrieval.h"
#include "activitylog.h"
#include "login.h"

UserBoxAccess::UserBoxAccess(QWidget *parent, QString user_) :
    QWidget(parent),
    ui(new Ui::UserBoxAccess)
{
    user = user_;

    ui->setupUi(this);

    update();
}

UserBoxAccess::~UserBoxAccess()
{
    delete ui;
}

void UserBoxAccess::on_logOutButton_clicked()
{
    log->write(user, "Log_out");
    login = new Login();
    login->move(0, 0);
    login->showFullScreen();
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
    sdbItems = dbi.getUserPrivileges(user, arraySize);
    for (int i = 0; i<arraySize; i++)
        ui->boxListWidget->addItem(&sdbItems[i]);

    if(ui->boxListWidget->count() == 0)
        ui->retrieveButton->setEnabled(false);
}

void UserBoxAccess::on_retrieveButton_clicked()
{
    boxret = new BoxRetrieval(0, "uba", user, ui->boxListWidget->currentItem()->text());
    boxret->move(0, 0);
    boxret->showFullScreen();

    this->close();
}
