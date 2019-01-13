#ifndef SHIP
#define SHIP
#include "technique.h"
class Ship : public Technique {
private:
    double totalDisplacement, maxSpeed, artilleryCaliber;
public:
    Ship();
    Ship(string _data,double _totalDisplacement, double _maxSpeed, double _artilleryCaliber);
    virtual string getData() const;
    Ship &operator =(const Ship &from);
    friend Ship operator +(const Ship &ship1, const Ship &ship2);
    friend Ship operator -(const Ship &ship1, const Ship &ship2);
    friend Ship operator &(const Ship &ship1, const Ship &ship2);
    friend bool operator >=(const Ship &ship1, const Ship &ship2);
    virtual void save(ostream &out) const;
    virtual void load(istream &in);
};

#endif // SHIP

