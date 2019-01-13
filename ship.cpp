#include "ship.h"

Ship::Ship() : Technique() {
    totalDisplacement = 0;
    maxSpeed = 0;
    artilleryCaliber = 0;
}

Ship::Ship(string _data,double _totalDisplacement, double _maxSpeed, double _artilleryCaliber) : Technique(_data) {
    totalDisplacement = _totalDisplacement;
    maxSpeed = _maxSpeed;
    artilleryCaliber = _artilleryCaliber;
}

//виртуальный метод сохранения в файл
void Ship::save(ostream &out) const {
    out << "Ship" << endl;
    out << data << endl;
    out << totalDisplacement << endl;
    out << maxSpeed << endl;
    out << artilleryCaliber << endl;
}

string Ship::getData() const {
    stringstream stream;
    stream << data << " (Водоизмещение: " << totalDisplacement << ", максимальная скорость: " << maxSpeed
           << ", Калибр: " << artilleryCaliber << ")";
    return string(stream.str());
}


//виртуальный метод загрузки из файла
void Ship::load(istream &in) {
    data = readString(in);
    totalDisplacement = readDouble(in);
    maxSpeed = readDouble(in);
    artilleryCaliber = readDouble(in);
}

//перегруженный оператор присваивания
Ship &Ship::operator =(const Ship &from) {
    this->data = from.data;
    this->totalDisplacement = from.totalDisplacement;
    this->maxSpeed = from.maxSpeed;
    this->artilleryCaliber = from.artilleryCaliber;
    return *this;
}

//перегруженные арифметические операторы(бесспысленные :D)
Ship operator +(const Ship &ship1, const Ship &ship2) {
    Ship result;
    result.data = ship1.data;
    result.maxSpeed = ship1.maxSpeed + ship2.maxSpeed;
    result.artilleryCaliber = ship1.artilleryCaliber +ship2.artilleryCaliber;
    result.totalDisplacement = ship1.totalDisplacement + ship2.totalDisplacement;
    return result;
}

Ship operator -(const Ship &ship1, const Ship &ship2) {
    Ship result;
    result.data = ship1.data;
    result.maxSpeed = ship1.maxSpeed - ship2.maxSpeed;
    result.artilleryCaliber = ship1.artilleryCaliber - ship2.artilleryCaliber;
    result.totalDisplacement = ship1.totalDisplacement - ship2.totalDisplacement;
    return result;
}

Ship operator &(const Ship &ship1, const Ship &ship2) {
    Ship result;
    result.data = ship1.data;
    result.maxSpeed = ship1.maxSpeed + ship2.maxSpeed;
    result.artilleryCaliber = ship1.artilleryCaliber * ship2.artilleryCaliber;
    result.totalDisplacement = ship1.totalDisplacement * ship2.totalDisplacement;
    return result;
}

//оператор сравнения
bool operator >=(const Ship &ship1, const Ship &ship2) {
    return ship1.maxSpeed >= ship2.maxSpeed && ship1.totalDisplacement >= ship2.totalDisplacement
            && ship1.artilleryCaliber >= ship2.artilleryCaliber;
}
