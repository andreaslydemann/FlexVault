#ifndef WEIGHTWARNINGDIALOG_H
#define WEIGHTWARNINGDIALOG_H

#include <QWidget>

namespace Ui {
class WeightWarningDialog;
}

class WeightWarningDialog : public QWidget
{
    Q_OBJECT

public:
    explicit WeightWarningDialog(QWidget *parent = 0);
    ~WeightWarningDialog();

private:
    Ui::WeightWarningDialog *ui;
};

#endif // WEIGHTWARNINGDIALOG_H
