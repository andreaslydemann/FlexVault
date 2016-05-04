#include "usercreationdialog.h"
#include "ui_usercreationdialog.h"
#include "userconfiguration.h"

UserCreationDialog::UserCreationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserCreationDialog)
{
    ui->setupUi(this);

    connect(this, SIGNAL(updateUserConfig()), this->parent(), SLOT(updateUConf()));
    connect(ui->userIDLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(lineEdit_textChanged()));
    connect(ui->passwordLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(lineEdit_textChanged()));

    lineEdit_textChanged();
}

UserCreationDialog::~UserCreationDialog()
{
    delete ui;
}

void UserCreationDialog::on_buttonBox_accepted()
{       
    QString uid = ui->userIDLineEdit->text();
    QString pw = ui->passwordLineEdit->text();

    dbi.writeUserToDb(uid, pw);
    emit updateUserConfig();
    this->close();
}

void UserCreationDialog::on_buttonBox_rejected()
{
    this->close();
}

void UserCreationDialog::lineEdit_textChanged()
{
    if(ui->userIDLineEdit->text().length() == 0 || ui->passwordLineEdit->text().length() == 0)
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    else
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}
