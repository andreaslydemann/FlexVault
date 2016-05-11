#include "adminboxaccess.h"
#include "ui_adminboxaccess.h"
#include "adminmainmenu.h"
#include "boxretrieval.h"

AdminBoxAccess::AdminBoxAccess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminBoxAccess)
{
    ui->setupUi(this);

    if(ui->boxListWidget->count() == 0)
        ui->retrieveButton->setEnabled(false);
}

AdminBoxAccess::~AdminBoxAccess()
{
    delete ui;
}

void AdminBoxAccess::on_retrieveButton_clicked()
{
    boxret = new BoxRetrieval(0, "aba", "Admin", ui->boxListWidget->currentItem()->text().mid(17,2));
    boxret->move(0, 0);
    boxret->show();

    this->close();
}

void AdminBoxAccess::on_backButton_clicked()
{
    amm = new AdminMainMenu();
    amm->move(0, 0);
    amm->show(); // change to showFullScreen() for BeagleBone
    this->close();
}
