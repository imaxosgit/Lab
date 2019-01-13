#ifndef TANKDIALOG_H
#define TANKDIALOG_H
#include "tank.h"
#include <QDialog>

namespace Ui {
class TankDialog;
}

class TankDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TankDialog(QWidget *parent = 0);
    Technique *show();
    ~TankDialog();

private:
    Ui::TankDialog *ui;
};

#endif // TANKDIALOG_H
