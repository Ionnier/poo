#include "include/menu.h"
#include "include/bloc_repository.h"

// O societate de investiții în imobiliare decide să construiască mai multe blocuri într-un complex dintr-o zonă atractivă din București.
// După finalizarea acestora, firma va dorii să vândă apartamentele printr-o companie de agenți imobiliari.
// Pentru documentarea tuturor operațiilor asupra acestor resurse, firma va apela la o platformă de gestionare în care va
// introduce detalii despre fiecare apartament.
//
// Aplicația va avea ca scop ușurarea mai multor operații:
// - vizualizarea tuturor blocurilor
// - adaugarea unui nou bloc (alaturi de componentele acestuia)
// - adăugarea și modificarea de apartamente din cadrul unui bloc
// - modificarea detaliilor unui bloc / apartament
// - crearea unei asocieri intre o listă de agenți imobiliari și apartamentele pe care le au în gestiune
// - afisarea unui istoric de vizualizare per agent imobiliar
// - afisarea unui istoric de vizualizare per apartament
// - posibilitatea de marcare a apartamentelor vandute

int main() {
    // Data generation, run once
    // BlocRepository bloc_repository("bloc_storage.txt");
    //
    // for (auto &bloc : bloc_repository.getBlocuri()) {
    //     std::cout << bloc << std::endl;
    // }

    // Bloc b(Adresa("strada1", "numar1"), "id1", {});
    // Bloc c(Adresa("strada2", "numar2"), "id2", {});
    // Bloc d(Adresa("strada3", "numar3"), "id3", {});
    //
    // Apartament a1(1, 10);
    // Apartament a2(2, 10);
    // Apartament a3(2, 10);
    // Scara bb("c", {a1, a2, a3});
    // Scara cc("c", {a1, a2});
    //
    // b.modificareScara(bb);
    // c.modificareScara(cc);
    //
    // bloc_repository.modifyBloc(b);
    // bloc_repository.modifyBloc(c);
    // bloc_repository.modifyBloc(d);

    Menu menu;
    menu.menuLoop();

    return 0;
}
