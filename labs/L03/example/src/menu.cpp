#include "../include/menu.h"
#include <iostream>

Menu::Menu() {
    options = {
        "Hello World"
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
            case 1:
                continue;
            case 0:
                return;
            default:
                std::cout << "Invalid option";
        }
    }
}

int Menu::requestInput() {
    int option;
    std::cout << "Option = ";
    std::cin >> option;
    return option;
}
