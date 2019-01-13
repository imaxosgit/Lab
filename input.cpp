#include "input.h"
#include "ui_input.h"

Input::Input(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::input)
{
    ui->setupUi(this);
}

string Input::getInput() const {
    return ui->lineEdit->text().toUtf8().constData();
}

Technique *Input::show() {
   if(exec() == QDialog::Accepted) {

   }
}

Input::~Input()
{
    delete ui;
}
