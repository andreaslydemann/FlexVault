#include "weightwarningdialog.h"
#include "ui_weightwarningdialog.h"

WeightWarningDialog::WeightWarningDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeightWarningDialog)
{
    QWidget::setWindowFlags( Qt::CustomizeWindowHint );
    ui->setupUi(this);
    ui->msgLabel->setWordWrap(true);
}

WeightWarningDialog::~WeightWarningDialog()
{
    delete ui;
}
