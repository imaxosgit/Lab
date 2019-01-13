#ifndef TANK
#define TANK
#include "technique.h"
class Tank : public Technique {
private:
    double mass, engineVolume;
    string engineType;
public:
    Tank();
    Tank(string _data, double _mass, double _engineVolume, string _engineType);
    virtual string getData() const;
    Tank &operator =(const Tank &from);
    virtual void save(ostream &out) const;
    virtual void load(istream &in);
};

#endif // TANK

