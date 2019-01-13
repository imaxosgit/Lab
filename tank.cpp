#include "tank.h"

Tank::Tank() : Technique() {
    mass = 0;
    engineVolume = 0;
    engineType = "";
}

//конструктор с инициализацией
Tank::Tank(string _data, double _mass, double _engineVolume, string _engineType) : Technique(_data) {
    mass = _mass;
    engineVolume = _engineVolume;
    engineType = _engineType;
}

//виртуальный метод сохранения в файл
void Tank::save(ostream &out) const {
    out << "Tank" << endl;
    out << data << endl;
    out << mass << endl;
    out << engineVolume << endl;
    out << engineType << endl;
}

string Tank::getData() const {
    stringstream stream;
    stream << data << " (Масса: " << mass << ", объем двигателя: " << engineVolume
           << ", тип двигателя: " << engineType << ")";
    return string(stream.str());
}

//виртуальный метод загрузки из файла
void Tank::load(istream &in) {
    data = readString(in);
    mass = readDouble(in);
    engineVolume = readDouble(in);
    engineType = readString(in);
}
