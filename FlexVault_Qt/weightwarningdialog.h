#ifndef WEIGHTWARNINGDIALOG_H
#define WEIGHTWARNINGDIALOG_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class WeightWarningDialog;
}

class WeightWarningDialog : public QWidget
{
    Q_OBJECT

public:
    explicit WeightWarningDialog(QWidget *parent = 0);
    ~WeightWarningDialog();

public slots:
    void closeDialog();

private:
    Ui::WeightWarningDialog *ui;
    static QTimer *timer;
};

#endif // WEIGHTWARNINGDIALOG_H
