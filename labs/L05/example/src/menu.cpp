#include "../include/menu.h"
#include <iostream>

#include "../include/angajat.h"
#include "../include/student.h"
#include "../include/student_angajat.h"

Menu::Menu() {
    options = {
        "Add person",
        "Display all persons",
        "Count number of students",
        "Modify person"
    };
}

void Menu::displayMenu() const {
    for (auto i = 0; i< options.size(); i++) {
        std::cout << i + 1 << ". " << options[i] << std::endl;
    }
    std::cout << "0. Exit" << std::endl;
}

void Menu::menuLoop() {
    while(true) {
        displayMenu();
        int option = requestInput();
        switch(option) {
            case 1: {
                std::cout<<"Type of employee(Persoana, Student, Angajat, StudentAngajat)= ";
                std::string choice;
                std::cin>>choice;

                Persoana *angajat;
                if (choice == "Persoana") {
                    angajat = new Persoana("nume", "prenume", {"1981217345678"});
                } else if (choice == "Student") {
                    angajat = new Student("nume", "prenume", {"1981217345678"}, "facultate", "an_admisie", 6);
                } else if (choice == "Angajat") {
                    angajat = new Angajat("nume", "prenume", {"1981217345678"}, "functie", 3000);
                } else if (choice == "StudentAngajat") {
                    angajat = new StudentAngajat("nume", "prenume", {"1981217345678"}, "facultate", "an_admisie", 6, "functie", 3000);
                } else {
                    std::cout << "Wrong choice!" << std::endl;
                    continue;
                }
                std::cin >> *angajat;
                _persons.push_back(angajat);
                break;
            }
            case 2: {
                for (const auto &person: _persons) {
                    std::cout << *person << std::endl;
                }
                break;
            }
            case 3: {
                int count = 0;
                Student *possibleStudent = nullptr;
                for (const auto &person: _persons) {
                    possibleStudent = dynamic_cast<Student*>(person);
                    if (possibleStudent != nullptr) {
                        count += 1;
                    }

                    // echivalent:
                    // if (typeid(person) == typeid(Persoana *))
                    // {
                    //     std::cout << typeid(person).name() << std::endl; // afiseaza lucruri variate in functie de compilator, in cazul meu P7Student, pointer 7 caractere [numele clasei]
                    //     count += 1;
                    // }

                }
                std::cout << "Number of students = " << count << std::endl;
                break;
            }
            case 4: {
                int index;
                std::cout << "Index of person = ";
                std::cin >> index;
                if (_persons.empty() || index < 0 || index >= _persons.size()) {
                    continue;;
                }

                std::cout << "1. Modifica nume\n";
                std::cout << "2. Modifica prenume\n";
                std::cout << "3. Modifica CNP\n";

                Persoana* selectedPerson = _persons[index];
                std::cin >> index;
                std::cout << "New value = ";
                switch (index) {
                    case 1: {
                        std::string newName;
                        std::cin >> newName;
                        selectedPerson->set_nume(newName);
                        break;
                    }
                    case 2: {
                        std::string newName;
                        std::cin >> newName;
                        selectedPerson->set_prenume(newName);
                        break;
                    }
                    case 3: {
                        CNP cnp("1981217345678");
                        std::cin >> cnp;
                        selectedPerson->set_cnp(cnp);
                        break;
                    }
                    default: {
                        std::cout << "Wrong option";
                        break;
                    }
                }
                break;
            }
            case 0: {
                return;
            }
            default: {
                std::cout << "Invalid option";
                break;
            }
        }
    }
}

int Menu::requestInput() {
    int option;
    std::cout << "Option = ";
    std::cin >> option;
    return option;
}

Menu::~Menu() {
    for (const auto &person: _persons) {
        delete person;
    }
}