#include "loginfaileddialog.h"
#include "ui_loginfaileddialog.h"

LoginFailedDialog::LoginFailedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginFailedDialog)
{
    ui->setupUi(this);
    ui->msgLabel->setWordWrap(true);
}

LoginFailedDialog::~LoginFailedDialog()
{
    delete ui;
}

void LoginFailedDialog::on_okButton_clicked()
{
    this->close();
}
