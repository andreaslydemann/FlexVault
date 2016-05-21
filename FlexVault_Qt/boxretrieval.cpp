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

    unsigned int cmd = 32;
    spi->writeToFV(&box_, &cmd);
}

BoxRetrieval::~BoxRetrieval()
{
    delete ui;
}

void BoxRetrieval::on_returnButton_clicked()
{
    if(spi->checkWeight())
    {
        wwd = new WeightWarningDialog();
        wwd->move(100, 100);
        wwd->show();
    }

    else
    {
        spi->returnSDB(box);
        log->write(user, "SDB_" + box + "_retrieved");
        InactivityFilter::resetTimer();

        if(prevPage == "uba")
        {
            uba = new UserBoxAccess(0, user);
            uba->showFullScreen();
            this->close();
        }

        if(prevPage == "aba")
        {
            aba = new AdminBoxAccess();
            aba->showFullScreen();
            this->close();
        }

        if(prevPage == "upriv")
        {
            upriv = new UserPrivileges(0, user);
            upriv->showFullScreen();
            this->close();
        }
    }
}
