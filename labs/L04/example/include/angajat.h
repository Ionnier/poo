#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <string>
#include "data.h"
#include <iostream>

class Angajat {
public:
    Angajat(const std::string&, const std::string&, const Data&);
    Angajat(const Angajat&);
    virtual ~Angajat() {
        // discard stuff from Angajat
        // if the class is going to be derived ALWAYS mark as virtual
        std::cout << "A" << std::endl;
    }
    Angajat& operator=(const Angajat&);
    friend std::ostream& operator<<(std::ostream&, const Angajat&);
    friend std::istream& operator>>(std::istream&, Angajat&);
    virtual int nrZileLibereAnulCurent() const = 0;

protected:
    virtual void citire(std::istream&);
    virtual void afisare(std::ostream&) const;
    Data data_angajare;

private:
    std::string nume;
    std::string prenume;
    const int id;
    static int id_seed;
};

#endif //ANGAJAT_H
