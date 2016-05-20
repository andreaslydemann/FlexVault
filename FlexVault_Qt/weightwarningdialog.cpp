#include "weightwarningdialog.h"
#include "ui_weightwarningdialog.h"

QTimer* WeightWarningDialog::timer = new QTimer;

WeightWarningDialog::WeightWarningDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeightWarningDialog)
{
    QWidget::setWindowFlags( Qt::CustomizeWindowHint );
    ui->setupUi(this);
    ui->msgLabel->setWordWrap(true);

    timer->setSingleShot(true);

    connect(timer, SIGNAL(timeout()), this, SLOT(closeDialog()));
    timer->start(4000);
}

void WeightWarningDialog::closeDialog()
{
    this->close();
}

WeightWarningDialog::~WeightWarningDialog()
{
    delete ui;
}
