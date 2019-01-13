#include "choosetype.h"
#include "ui_choosetype.h"
#include "tankdialog.h"
#include "shipdialog.h"

ChooseType::ChooseType(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseType)
{
    ui->setupUi(this);
}

Technique *ChooseType::show() {
    if(exec() == QDialog::Accepted) {
        if(ui->comboBox->itemText(ui->comboBox->currentIndex()) == "Танк") {
            TankDialog td;
            return td.show();
        }
        else {
            ShipDialog sd;
            return sd.show();
        }
    }
    else return NULL;
}

ChooseType::~ChooseType()
{
    delete ui;
}
