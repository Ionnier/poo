#ifndef ANGAJAT_TEMPORAR_H
#define ANGAJAT_TEMPORAR_H
#include "angajat.h"

class AngajatTemporar: public Angajat {
public:
    AngajatTemporar(const Data&, const std::string&, const std::string&, const Data&);
    AngajatTemporar(const AngajatTemporar&) = default;
    ~AngajatTemporar() = default;
    AngajatTemporar& operator=(const AngajatTemporar&) = default;
    int nrZileLibereAnulCurent() const override;

private:
    Data dataIncheiere;
    void afisare(std::ostream &) const override;
    void citire(std::istream &) override;
};

#endif //ANGAJAT_TEMPORAR_H
