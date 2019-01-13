#include "technique.h"
#include <stdlib.h>
#include <QMessageBox>
//конструктор по умолчанию. Данные вводятся из консоли
Technique::Technique() {

}

//конструктор с инициализацией
Technique::Technique(string _data) {
    data = _data;
}

//копирующий конструктор
Technique::Technique(const Technique &t) {
    data = t.data;
}

//вспомогательные функции чтения
double Technique::readDouble(istream &in) {
    return atof(readString(in).c_str());
}

string Technique::readString(istream &in) {
    char buff[100];
    in.getline(buff, 100);
    return buff;
}

//потоковые вывод/ввод
ostream &operator <<(ostream &out, Technique *tech) {
    tech->save(out);
    return out;
}

istream &operator >>(istream &in, Technique *tech) {
    tech->load(in);
    return in;
}

void Technique::operator ()() const {
    QMessageBox *msg = new QMessageBox;
    msg->setInformativeText(getData().c_str());
    msg->setStandardButtons(QMessageBox::Ok);
    msg->setDefaultButton(QMessageBox::Ok);
    msg->exec();
}

Technique::~Technique() {

}
