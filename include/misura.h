#ifndef Misura_h
#define Misura_h

#include <iostream>

#include "lettura.h"
//#include "misura.h"

class Misura{
    public:

    //per poter lanciare errori
    class Invalid {};

    //costruttori

    Misura();

    Misura(std::initializer_list<Lettura> lst);

    //costruttore copia
    Misura(const Misura& m);

    //assegnamento copia
    Misura& operator=(const Misura& m);

    //costruttore move
    Misura(Misura&& m);

    //assegnamento move
    Misura& operator=(Misura&& m);

    //l'operator[] emula il comportamento degli array stile C
    Lettura& operator[](int n);
    const Lettura& operator[] (int n) const;

    //il metodo aiuta ad evitare magic numbers (size è costante e non scelta dall'utente)
    int size() const { return NUM_LETTURE; }

    private:
    static const int NUM_LETTURE {17};
    Lettura elem[NUM_LETTURE];
};

//operator<< per Misura
std::ostream& operator<<(std::ostream& os, Misura m);

//operator <<  per Lettura
std::ostream& operator<<(std::ostream& os, Lettura l);

#endif //Misura_h