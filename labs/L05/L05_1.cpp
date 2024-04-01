#include <iostream>
using namespace std;

class MijlocTransport {
private:
    int pret_initial;
    int pret_metentanta;
    int pret_km;
    int id;
    static int last_id;
public:
    MijlocTransport(int pret_initial, int pret_metentanta, int pret_km)
        :pret_initial(pret_initial), pret_metentanta(pret_metentanta), pret_km(pret_km), id(last_id)
     {
        last_id++;
    }
    virtual ~MijlocTransport() {

    }

    virtual void afisare(ostream & out) const {
        out << "MijlocTransport(id = " << id << ")";
    }

    friend ostream& operator<<(ostream& out, const MijlocTransport &aux) {
        aux.afisare(out);
        return out;
    }

};
int MijlocTransport::last_id = 0;

class MijlocTransportPoluant: virtual public MijlocTransport {
private:
    int factor_poluare;
public:
    MijlocTransportPoluant(int factor_poluare, int pret_initial, int pret_mentenanta, int pret_km): MijlocTransport(pret_initial, pret_mentenanta, pret_km), factor_poluare(factor_poluare)  {

    }
    ~MijlocTransportPoluant() {

    }
    void afisare(ostream & out) const {
        MijlocTransport::afisare(out);
        out << " | MijlocTransportPoluant(factor_poluare = " << factor_poluare << ")";
    }

};

class MijlocTransportEcologic: virtual public MijlocTransport {
private:
    int acumulator;
public:
    MijlocTransportEcologic(int acumulator, int pret_initial, int pret_mentenanta, int pret_km): MijlocTransport(pret_initial, pret_mentenanta, pret_km), acumulator(acumulator)  {

    }
    ~MijlocTransportEcologic() {

    }
    void afisare(ostream & out) const {
        MijlocTransport::afisare(out);
        out << " | MijlocTransportEcologic(acumulator = " << acumulator << ")";
    }

};


int main() {
    MijlocTransportEcologic a(1, 2, 3, 4);
    cout << a;
    
}