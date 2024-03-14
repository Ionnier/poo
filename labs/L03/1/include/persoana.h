#ifndef OOP_PERSOANA_H
#define OOP_PERSOANA_H
#include <iostream>
#include <string>
using namespace std;
class Persoana {
private:
    string nume;
public:
    Persoana(const string &nume = "");

    friend ostream& operator<<(ostream&, const Persoana&);

    bool operator==(const Persoana p) const;
};
#endif //OOP_PERSOANA_H
