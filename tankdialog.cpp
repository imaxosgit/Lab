#include "tankdialog.h"
#include "ui_tankdialog.h"
#include <stdlib.h>

TankDialog::TankDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TankDialog)
{
    ui->setupUi(this);
}

//ввод данных из диалога и создание нового танка
Technique *TankDialog::show() {
    if(exec() == QDialog::Accepted)
        return new Tank(ui->lineEdit->text().toUtf8().constData(),
                        atof(ui->lineEdit_2->text().toUtf8().constData()),
                        atof(ui->lineEdit_3->text().toUtf8().constData()),
                        ui->lineEdit_4->text().toUtf8().constData());
    else return NULL;
}

TankDialog::~TankDialog()
{
    delete ui;
}
