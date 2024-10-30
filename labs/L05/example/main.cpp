#include <iostream>

#include "include/menu.h"


int main() {
    Menu m;
    m.menuLoop();
    return 0;
}

/*
 * 1. Adaugati un field numit id pe clasa de baza Persoana incrementat automat
 * 2. Ce se intampla daca in sistemul de try-catch blocul de catch cu argument  clase de baza este deasupra blocului de
 *  catch al unei clase derivate si noi aruncam o instanta a unei clase derivata
 * 3. Comentati implementarea optiunii 4 din meniu.
 * 4. Una din problemele din exercitiul precedent este imbricarea multor meniuri unul sub altul (meniul principal -> meniul de modificare)
 *      in cazul de fata erau doar 2, dar daca erau 5+? Acesta este unul din cazurile care necesita un refactor.
 *      Gasiti o solutie care sa permita separarea celor doua.
 *
 *      Idee:
 *          Crearea unei noi componente de navigare, se practica ideea de existenta unui graf de navigare (sau o lista de navigare), astfel exista o componenta
 *          ce coordoneaza toate meniurile pe care vrem sa le afisam, iar scopul ei este sa o afiseze pe ultima plasata.
 *                  class NavGraph;

                    class SubMenu {
                    public:
                        virtual ~SubMenu() = default;
                        virtual void loop() = 0;
                        void goBack() const;
                        void goNext(SubMenu* nextMenu) const;

                        explicit SubMenu(NavGraph *parent)
                            : parent(parent) {
                        }

                    protected:
                        NavGraph *parent;
                    };

                    class NavGraph {
                    public:
                        void loop();
                        void goNext(SubMenu *menu);
                        void goBack();

                    private:
                        std::vector <SubMenu*> _menus;
                    };

 *              Orice meniu pe care vrem sa il implementam va mostenii clasa sub menu si va fi adaugat in NavGraph.
 * 5. Cat mai multe nivele din https://learngitbranching.js.org/ (screenshot)
 *
 *
 */