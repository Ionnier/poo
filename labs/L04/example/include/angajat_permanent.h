#ifndef ANGAJAT_PERMANENT_H
#define ANGAJAT_PERMANENT_H
#include "angajat.h"

class AngajatPermanent: public Angajat {
public:
    AngajatPermanent(int, const std::string &, const std::string&, const Data&);
    AngajatPermanent(const AngajatPermanent&);
    AngajatPermanent& operator=(const AngajatPermanent&);
    int nrZileLibereAnulCurent() const;
    ~AngajatPermanent() {
        // discard stuff only for AngajatPermanent
        // if original destructor is virtual
        // this will be automatically called

        // derived classes destructor will always be called first, after that base class destructor
        std::cout << "B" << std::endl;
    }

private:
    int nrZileRamaseAnulTrecut;

    void citire(std::istream&);
    void afisare(std::ostream&) const;
};

#endif //ANGAJAT_PERMANENT_H
