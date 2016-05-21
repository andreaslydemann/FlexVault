#include "adminmainmenu.h"
#include "ui_adminmainmenu.h"
#include "userconfiguration.h"
#include "activitylog.h"
#include "login.h"
#include "adminboxaccess.h"

AdminMainMenu::AdminMainMenu(QWidget *parent) :
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
    uconf->showFullScreen();
    this->close();
}

void AdminMainMenu::on_logOutButton_clicked()
{
    log->write("Admin", "Log_out");
    login = new Login(0);
    login->showFullScreen();

    this->close();
}

void AdminMainMenu::on_logButton_clicked()
{
    log = new ActivityLog();
    log->showFullScreen();
    this->close();
}

void AdminMainMenu::on_sdbButton_clicked()
{
    aba = new AdminBoxAccess();
    aba->showFullScreen();
    this->close();
}
