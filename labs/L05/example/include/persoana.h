#ifndef PERSOANA_H
#define PERSOANA_H
#include <string>
#include <iostream>
#include "../include/cnp.h"

class Persoana: public Readable, public Displayable {
public:
    virtual ~Persoana() = default;
    Persoana(const std::string &nume, const std::string &prenume, const CNP &cnp)
        : _nume(nume),
          _prenume(prenume),
          _cnp(cnp) {
    }
    Persoana(const Persoana &other) = default;
    Persoana & operator=(const Persoana &other) = default;

    [[nodiscard]] std::string nume() const {
        return _nume;
    }

    void set_nume(const std::string &nume) {
        _nume = nume;
    }

    [[nodiscard]] std::string prenume() const {
        return _prenume;
    }

    void set_prenume(const std::string &prenume) {
        _prenume = prenume;
    }

    [[nodiscard]] CNP cnp() const {
        return _cnp;
    }

    void set_cnp(const CNP &cnp) {
        _cnp = cnp;
    }

    virtual int incomeLunar();

protected:
    void afisare(std::ostream&) const override;
    void citire(std::istream&) override;
    virtual int calculareIncome();

private:

    std::string _nume;
    std::string _prenume;
    CNP _cnp;

};

#endif //PERSOANA_H
