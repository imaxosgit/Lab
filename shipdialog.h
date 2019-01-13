#ifndef SHIPDIALOG_H
#define SHIPDIALOG_H
#include "ship.h"
#include <QDialog>

namespace Ui {
class ShipDialog;
}

class ShipDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShipDialog(QWidget *parent = 0);
    Technique *show();
    ~ShipDialog();

private:
    Ui::ShipDialog *ui;
};

#endif // SHIPDIALOG_H
