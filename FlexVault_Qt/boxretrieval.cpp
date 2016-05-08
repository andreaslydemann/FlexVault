#include "boxretrieval.h"
#include "ui_boxretrieval.h"
#include "userprivileges.h"
#include "adminboxaccess.h"
#include "userboxaccess.h"

BoxRetrieval::BoxRetrieval(QWidget *parent, QString prevPage_, QString user_) :
    QWidget(parent),
    ui(new Ui::BoxRetrieval)
{
    prevPage = prevPage_;
    user = user_;
    ui->setupUi(this);
}

BoxRetrieval::~BoxRetrieval()
{
    delete ui;
}

void BoxRetrieval::on_returnButton_clicked()
{
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
        aba->show(); // change to showFullScreen() for BeagleBone
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
