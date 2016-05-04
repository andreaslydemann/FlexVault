#include "adminmainmenu.h"
#include "ui_adminmainmenu.h"
#include "userconfiguration.h"
#include "login.h"
AdminMainMenu::AdminMainMenu(QWidget *parent, QSqlDatabase*) :
    QWidget(parent),
    ui(new Ui::AdminMainMenu)
{
    ui->setupUi(this);
}

AdminMainMenu::~AdminMainMenu()
{
    delete ui;
}

void AdminMainMenu::on_usersButton_clicked()
{
    uconf = new UserConfiguration();
    uconf->show(); // change to showFullScreen() for BeagleBone
    this->close();
}

void AdminMainMenu::on_logOutButton_clicked()
{
    login = new Login(0, fv_db);
    login->show();
    this->close();
}
