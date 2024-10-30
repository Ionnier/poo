#ifndef STUDENT_ANGAJAT_H
#define STUDENT_ANGAJAT_H
#include "student.h"
#include "angajat.h"

class StudentAngajat: public Student, public Angajat {
public:
    StudentAngajat(const std::string &nume, const std::string &prenume, const CNP &cnp, const std::string &facultate,
        const std::string &an_admisie, int nr_semestre, const std::string &functie, int salariu)
        : Persoana(nume, prenume, cnp),
          Student(nume, prenume, cnp, facultate, an_admisie, nr_semestre), Angajat(nume, prenume, cnp, functie, salariu) {
    }

    int incomeLunar() override {
        // functie care agregeaza toate functiile
        return Student::calculareIncome()
            + Angajat::calculareIncome()
            + Persoana::calculareIncome()
            + calculareIncome();
    }

protected:
    int calculareIncome() override {
        return 0;
    }

private:
    void afisare(std::ostream &out) const override {
        out << "StudentAngajat(Student= ";
        Student::afisare(out);
        out << ", Angajat=";
        // se va afisa duplicat,
        Angajat::afisare(out);
        // poate nu ne deranjeaza?
        out << ")";
    }

    void citire(std::istream &in) override {
        // alta alternativa e sa apelam functiile dintr-una din clase
        Student::citire(in);
        // si o tratam pe cealalta separat
        std::cout << "functie= ";
        in >> functie;
        std::cout << "salariu= ";
        in >> salariu;
        // dar duplicam codul, ceea ce nu e avantajos in unele situatii
    }
};

#endif //STUDENT_ANGAJAT_H
