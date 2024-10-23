#include "../include/menu.h"
#include <iostream>

#include "../include/angajat_permanent.h"
#include "../include/angajat_temporar.h"

Menu::Menu() {
    options = {
        "Add employee",
        "Display all employees",
        "Display number of free days for the index of an employee"
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
                std::cout<<"Type of employee(Temporar, Permanent)= ";
                std::string choice;
                std::cin>>choice;

                Angajat *angajat;
                if (choice == "Temporar") {
                    angajat = new AngajatTemporar({1, 1, 1}, "1", "1", {1, 1, 1});
                } else if (choice == "Permanent") {
                    angajat = new AngajatPermanent(0, "1", "1", {1, 1, 1});
                } else {
                    std::cout << "Wrong choice!" << std::endl;
                }
                std::cin >> *angajat;
                storage.push_back(angajat);
                break;
            }
            case 2: {
                for (auto &angajat: storage) {
                    std::cout << *angajat << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "index= ";
                int x;
                std::cin >> x;
                if (x < 0 || x > storage.size()) {
                    std::cout << "Wrong index" << std::endl;
                    break;
                }
                std::cout << "Nr zile anul curent = " << storage[x]->nrZileLibereAnulCurent() << std::endl;
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
    // we use manually allocated storage so we need to dealoc when we destroy the object
    for (auto & i : storage) {
        delete i;
    }
    storage.clear();
}
