#ifndef STUDENT_H
#define STUDENT_H
#include "persoana.h"
#include <string>
class Student: public virtual Persoana {
public:
    Student(const std::string &nume, const std::string &prenume, const CNP &cnp, const std::string &facultate,
        const std::string &an_admisie, int nr_semestre)
        : Persoana(nume, prenume, cnp),
          facultate(facultate),
          an_admisie(an_admisie),
          nr_semestre(nr_semestre) {
    }
    int incomeLunar() override;

protected:
    void afisare(std::ostream &) const override;
    void citire(std::istream &in) override;
    int calculareIncome() override;

private:
    std::string facultate;
    std::string an_admisie;
    int nr_semestre;
};


#endif //STUDENT_H
