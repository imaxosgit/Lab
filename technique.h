#ifndef TECHNIQUE
#define TECHNIQUE
#include <iostream>
#include <sstream>
using namespace std;

class Technique {
protected:
    string data;
public:
    Technique();
    Technique(string _data);
    Technique(const Technique &t);
    virtual string getData() const { return data; }
    void setData(string newData) { data = newData; }
    virtual void save(ostream &out) const = 0;
    virtual void load(istream &in) = 0;
    static double readDouble(istream &in);
    static string readString(istream &in);
    friend ostream &operator <<(ostream &out, Technique *tech);
    friend istream &operator >>(istream &in, Technique *tech);
    void operator ()() const;
    ~Technique();
};

#endif // TECHNIQUE
