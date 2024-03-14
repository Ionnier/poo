#include <iostream>
#include <biblioteca.h>

using namespace std;

void afisare_status_imprumut(bool value) {
    if (value) {
        cout << "A fost imprumutata\n";
        return;
    }
    cout << "Nu a fost imprumutata\n";
}

void menu() {
    vector<string> mesaje = {
            "Afisare persoane",
            "Afisare biblioteca",
            "Adaugare carte",
            "Eliminare carte",
            "Imprumuta carte",
            "Returnare carte"
    };
    for (int i = 0; i < mesaje.size(); i++) {
        cout << i + 1 << ". " << mesaje[i] << endl;
    }
    cout << "Optiune = ";
}

int main() {
    int n;
    bool continua = true;
    vector<Persoana> persoane = {
        Persoana("Persoana 1"),
        Persoana("Persoana 2"),
        Persoana("Persoana 3"),
    };
    Biblioteca b;
    while(continua) {
        menu();
        cin >> n;
        switch (n) {
            case 1: {
                for (auto &persoana: persoane){
                    cout << persoana << endl;
                }
                break;
            }
            case 2: {
                cout << b << endl;
                break;
            }
            case 3: {
                Carte c;
                cin >> c;
                b.adauga_carte(c);
                break;
            }
            case 4: {
                Carte c;
                cin >> c;
                b.elimina_carte(c);
                break;
            }
            case 5: {
                cout << "Index persoana";
                int index;
                cin >> index;
                if (index < 0 || (index + 1) > persoane.size()) {
                    cout << "Person not found";
                    break;
                }
                Carte c;
                cin >> c;
                afisare_status_imprumut(b.imprumuta_carte(&persoane[index], c));
                break;
            }
            case 6: {
                cout << "Index persoana" << endl;
                int index;
                cin >> index;
                if (index < 0 || (index + 1) > persoane.size()) {
                    cout << "Person not found" << endl;
                    break;
                }
                Carte c;
                cin >> c;
                b.retur_carte(&persoane[index], c);
                break;
            }
            case 0: {
                continua = false;
                break;
            }
            default: {
                cout << "Not implemented\n";
            }
        }
        if (continua) {
            cout << "Press any key to contiune...";

            // Twice because when you read ints you
            //   already have one RETURN character in buffer
            // worst case, you have to press twice
            cin.get();
            cin.get();
        }
    }
    return 0;
}
