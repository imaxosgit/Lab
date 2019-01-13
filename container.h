#ifndef CONTAINER
#define CONTAINER
#include "technique.h"
#include <deque>
typedef Technique * Tech;

template <class T>
class Container {
private:
    deque<T> militaryTech;
public:
    Container();
    typename deque<T>::const_iterator begin() const { return militaryTech.begin(); }
    typename deque<T>::const_iterator end() const { return militaryTech.end(); }
    int size() const { return militaryTech.size(); }
    void show();
    void add_front(T t);
    void add_back(T t);
    void delete_front();
    void delete_back();
    void operator --() { delete_front(); } //префиксный
    void operator --(int) { delete_back(); } // постфиксный
    T operator [](int index) { return militaryTech[index]; } //индексация
    void save() const;
    void load();
    void clear() { militaryTech.clear(); }
    //friend Tech(const S &t, const B &b);
    ~Container();
};

#endif // CONTAINER
