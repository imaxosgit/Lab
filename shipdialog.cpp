#include "shipdialog.h"
#include "ui_shipdialog.h"

ShipDialog::ShipDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShipDialog)
{
    ui->setupUi(this);
}

//ввод данных из диалога и создание нового корабля
Technique *ShipDialog::show() {
    if(exec() == QDialog::Accepted)
        return new Ship(ui->lineEdit->text().toUtf8().constData(),
                        atof(ui->lineEdit_2->text().toUtf8().constData()),
                        atof(ui->lineEdit_3->text().toUtf8().constData()),
                        atof(ui->lineEdit_4->text().toUtf8().constData()));
    else return NULL;
}

ShipDialog::~ShipDialog()
{
    delete ui;
}
