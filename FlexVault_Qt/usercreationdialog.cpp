#include "usercreationdialog.h"
#include "ui_usercreationdialog.h"
#include "userconfiguration.h"
#include "activitylog.h"

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
    log->write(ui->userIDLineEdit->text(),"Created");
    emit updateUserConfig();
    this->close();
}

void UserCreationDialog::on_buttonBox_rejected()
{
    this->close();
}

void UserCreationDialog::lineEdit_textChanged()
{
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);

    if(ui->userIDLineEdit->text().length() == 0 || ui->passwordLineEdit->text().length() == 0)
    {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        return;
    }

    for(int i = 0; i < ui->userIDLineEdit->text().length(); i++)
        if(ui->userIDLineEdit->text().at(i) == ' ')
        {
            ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
            return;
        }

    for(int i = 0; i < ui->passwordLineEdit->text().length(); i++)
        if(ui->passwordLineEdit->text().at(i) == ' ')
        {
            ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
            return;
        }
}
