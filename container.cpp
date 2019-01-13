#include "container.h"
#include <fstream>
#include "tank.h"
#include "ship.h"

template <class T>
Container<T>::Container() {

}

template <class T>
void Container<T>::add_front(T t) {
    militaryTech.push_front(t);
}

template <class T>
void Container<T>::add_back(T t) {
    militaryTech.push_back(t);
}

template <class T>
void Container<T>::delete_front() {
    militaryTech.pop_front();
}

template <class T>
void Container<T>::delete_back() {
    militaryTech.pop_back();
}

template <class T>
void Container<T>::show() {
    for(typename deque<T>::iterator it = militaryTech.begin(); it != militaryTech.end(); it++)
        cout << (*it)->getData() << endl;
}

template <class T>
Container<T>::~Container() {
    for(typename deque<T>::iterator it = militaryTech.begin(); it != militaryTech.end();)
        it = militaryTech.erase(it);
}

template <class T>
void Container<T>::save() const {
    try {
        ofstream out("lab3.dat");
        if(!out) throw "couldn't open file lab3.dat";
        for(typename deque<T>::const_iterator it = militaryTech.begin(); it != militaryTech.end(); it++)
            out << *it;
        out.close();
    } catch (char const *message) {
        cout << message << endl;
    }
}

template <class T>
void Container<T>::load() {
    try {
        ifstream in("lab3.dat");
        if(!in) return;
        while(!in.eof()) {
            char buff[100];
            in.getline(buff, 100);
            T tech;
            if(!strcmp(buff, "Tank"))
                tech = new Tank();
            else if(!strcmp(buff, "Ship"))
                tech = new Ship();
            else if(!strcmp(buff, "")) return;
            else throw "trash in file";
            in >> tech;
            militaryTech.push_back(tech);
        }
        in.close();
    } catch (char const *message) {
        cout << message << endl;
    }
}
