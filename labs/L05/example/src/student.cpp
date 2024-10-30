#include "../include/student.h"

void Student::afisare(std::ostream &out) const {
    out << "Angajat(facultate" << facultate << ", an_admisie=" << an_admisie << ", nr_semestre="<< nr_semestre << "persoana=";
    Persoana::afisare(out);
    out << ")";
}

void Student::citire(std::istream &in) {
    Persoana::citire(in);
    std::cout << "facultate = ";
    in >> facultate;
    std::cout << "an_admisie = ";
    in >> an_admisie;
    std::cout << "nr_semestre = ";
    in >> nr_semestre;
}

int Student::incomeLunar() {
    return Persoana::incomeLunar() + calculareIncome();
}

int Student::calculareIncome() {
    // bursa? dar e deja prea tarziu sa mai fac variabile :(
    return 1200;
}
