#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>
#include "angajat.h"

class Menu {
public:
    Menu();
    ~Menu();
    void menuLoop();
private:
    std::vector<std::string> options;
    std::vector<Angajat*> storage;

    // we make copy constructor and operator= private to prevent copying of the clasee
    // we can either make them private, or delete the compiler generated code
    // both options make on of them redundent
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;


    void displayMenu() const;
    int requestInput();
};
#endif //MENU_H