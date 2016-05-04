#include "userboxaccess.h"
#include "ui_userboxaccess.h"

UserBoxAccess::UserBoxAccess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserBoxAccess)
{
    ui->setupUi(this);
}

UserBoxAccess::~UserBoxAccess()
{
    delete ui;
}
