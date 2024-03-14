//
// Created by Dragos BAHRIM on 14.03.2024.
//

#ifndef OOP_VIDEOCLIP_H
#define OOP_VIDEOCLIP_H
#include <string>
#include <comentariu.h>
using namespace std;

class Videoclip {
private:
    string nume;
    vector<Comentariu> comentarii;
public:
    Videoclip(const string nume);
    friend ostream &operator<<(ostream &out, const Videoclip v);
    void adauga_comentariu(const string &mesaj) {
        comentarii.push_back(Comentariu(mesaj));
    }
};
#endif //OOP_VIDEOCLIP_H
