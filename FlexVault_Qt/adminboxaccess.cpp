#include "adminboxaccess.h"
#include "ui_adminboxaccess.h"
#include "adminmainmenu.h"
#include "boxretrieval.h"
#include "spiinterface.h"

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
    //if(spi->checkStatus())
    {
        boxret = new BoxRetrieval(0, "aba", "Admin", ui->boxListWidget->currentItem()->text().mid(17,2));
        boxret->showFullScreen();
        this->close();
    }
}

void AdminBoxAccess::on_backButton_clicked()
{
    amm = new AdminMainMenu();
    amm->showFullScreen();
    this->close();
}
