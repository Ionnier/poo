#include "include/menu.h"

int main()
{
    Menu menu;
    menu.menuLoop();
}

// Exercitii:

// 1. Comentati urmatoare portiune de cod.
// (este considerat ca nu functioneaza corect, mentionati de ce nu functioneaza cum trebuie si cum ar trebui corectat)
// #include <iostream>
//
// class A {
// public:
//     virtual void afisare(std::ostream &out) const {
//         std::cout << "A";
//     }
//     friend std::ostream& operator<<(std::ostream& out, const A a) {
//         a.afisare(out);
//         return out;
//     }
// };
//
// class B: public A {
// public:
//     void afisare(std::ostream &out) const {
//         out << "B";
//     }
// };
// int main()
// {
//     B b;
//     std::cout << b;
// }

// 2. Folositi o ierarhie derivate pentru a demonstra daca exista o
// logica in modul de inlantuire a variabilelor in lantul de initializare a constructorului
// see also: https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c47-define-and-initialize-data-members-in-the-order-of-member-declaration

// 3. Ce face cuvantul special 'override' atunci cand redefinim functii virtuale in clase derivate?

// 4. Creati ierarhia de clase "Logger"
// se doreste existenta unei clase Logger ce are ca scopul scrierea de mesaje pe un canal
// fiecare mesaj va avea formatul W 2024.10.23 14:35 [nume mesaj]
//                      W = warn, acesta este nivelul log-ului
//                      vor exista 5 nivele, Debug (D), Warn (W), Info(I), Error(E), Trace(T)
//                      documentati-va ce inseamna fiecare nivel
//                      oferiti support pentru aceasta clasa logger ca sa afiseze log-uri doar de la un anumit nivel de severitate

// Logger va fi o clasa abstracta
// vor exista 3 derivate, ConsoleLogger ce va afisa datele catre cout (cout = character out)
//                        FileLogger ce va afisa datele catre un fisier
//                        LoggerDistributor care va trimite mesajele de logging catre mai multe obiecte de tip logging in acelasi timp
//                              (de exemplu poate trimite mesaje de logging catre un ConsoleLogger si un FileLogger in acelasi timp)

// Demonstrati ca functioneaza implementarea
// Veti folosii fiecare clasa prin intermediul clasei abstracte si nu prin obiectul concret

// 5. Imitați comportamentul pasării de pointeri la funcții din C printr-o ierarhie de clase ce porneste dintr-o clasa abstracta.
// Este aproape echivalent cu comportamentul funcțiilor lambda
// #include <iostream>
// #include <algorithm>
// #include <vector>
//
// int main() {
//     std::vector<int> numbers = {5, 2, 9, 1, 6, 3};
//
//     std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
//         return a < b;
//     });
//
//     std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
//         return a > b;
//     });
// }

// Practic, creati o functie sort care va aplica algoritmul de sortare dar cu algoritmi de ordonare diferiti ce este dat in momentul executiei





























