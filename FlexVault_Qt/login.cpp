#include "login.h"
#include "ui_login.h"
#include "adminmainmenu.h"
#include "loginfaileddialog.h"
#include "activitylog.h"
#include "userboxaccess.h"
#include "inactivityfilter.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    connect(ui->idLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(lineEdit_textChanged()));
    connect(ui->passwordLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(lineEdit_textChanged()));
    lineEdit_textChanged();

    ui->flexVaultLabel->setFocus();

    ui->idLineEdit->installEventFilter(this);
    ui->passwordLineEdit->installEventFilter(this);

    ui->virtualKeyboard->hide();

    InactivityFilter::stopTimer();
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    if((ui->idLineEdit->text() == "Admin" && ui->passwordLineEdit->text() == "Admin") ||
            (ui->idLineEdit->text() == "admin" && ui->passwordLineEdit->text() == "admin"))
    {
        InactivityFilter::resetTimer();

        log->write("Admin", "Log_in");

        amm = new AdminMainMenu(NULL);
        amm->showFullScreen();
        this->close();
    }

    else if(dbi.validateLogin(ui->idLineEdit->text(), ui->passwordLineEdit->text()))
    {
        InactivityFilter::resetTimer();

        log->write(ui->idLineEdit->text(), "Log_in");

        uba = new UserBoxAccess(NULL, ui->idLineEdit->text());
        uba->showFullScreen();
        this->close();
    }

    else
    {
        lfd = new LoginFailedDialog(this);
        lfd->show();
    }
}

void Login::lineEdit_textChanged()
{
    if(ui->idLineEdit->text().length() == 0 || ui->passwordLineEdit->text().length() == 0)
        ui->loginButton->setEnabled(false);

    else
        ui->loginButton->setEnabled(true);
}

bool Login::eventFilter(QObject* object, QEvent* event)
{
    if((object == ui->idLineEdit || object == ui->passwordLineEdit) && event->type() == QEvent::MouseButtonPress) {
        ui->virtualKeyboard->show();
        return false;
    }
    return false;
}

