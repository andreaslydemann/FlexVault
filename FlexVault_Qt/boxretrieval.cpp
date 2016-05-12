#include "boxretrieval.h"
#include "ui_boxretrieval.h"
#include "userprivileges.h"
#include "adminboxaccess.h"
#include "userboxaccess.h"
#include "inactivityfilter.h"
#include "activitylog.h"
#include "weightwarningdialog.h"
#include "spiinterface.h"

BoxRetrieval::BoxRetrieval(QWidget *parent, QString prevPage_, QString user_, QString box_) :
    QWidget(parent),
    ui(new Ui::BoxRetrieval)
{
    ui->setupUi(this);

    ui->msgLabel->setWordWrap(true);

    prevPage = prevPage_;
    user = user_;
    box = box_;

    InactivityFilter::stopTimer();

    unsigned int cmd = 17408;
    spi->writeToFV(&box_, &cmd);
}

BoxRetrieval::~BoxRetrieval()
{
    delete ui;
}

void BoxRetrieval::on_returnButton_clicked()
{
    InactivityFilter::resetTimer();
    log->write(user, "SDB_" + box + "_retrieved");

    spi->readFromFV();

    if(prevPage == "uba")
    {
        uba = new UserBoxAccess(0, user);
        uba->move(0, 0);
        uba->show(); // change to showFullScreen() for BeagleBone
        this->close();
    }

    if(prevPage == "aba")
    {
        aba = new AdminBoxAccess();
        aba->move(0, 0);
        aba->showFullScreen(); // change to showFullScreen() for BeagleBone
        this->close();
    }

    if(prevPage == "upriv")
    {
        upriv = new UserPrivileges(0, user);
        upriv->move(0, 0);
        upriv->show(); // change to showFullScreen() for BeagleBone
        this->close();
    }
}
