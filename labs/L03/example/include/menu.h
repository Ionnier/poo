#ifndef MENU_H
#define MENU_H
#include <vector>
#include <string>

class Menu {
public:
    Menu();
    void menuLoop();
private:
    std::vector<std::string> options;

    // we make copy constructor and operator= private to prevent copying of the clasee
    // we can either make them private, or delete the compiler generated code
    // both options make on of them redundent
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;


    void displayMenu() const;
    int requestInput();
};
#endif //MENU_H
