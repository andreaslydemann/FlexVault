#include "boxretrieval.h"
#include "ui_boxretrieval.h"

BoxRetrieval::BoxRetrieval(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BoxRetrieval)
{
    ui->setupUi(this);
}

BoxRetrieval::~BoxRetrieval()
{
    delete ui;
}
