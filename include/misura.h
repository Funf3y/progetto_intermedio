#ifndef Misura_h
#define Misura_h

#include <iostream>

#include "lettura.h"

class Misura{
    public:

    //per poter lanciare errori
    class Invalid {};

    //costruttori

    Misura();

    Misura(std::initializer_list<Lettura> lst);

    //costruttore copia
    Misura(const Misura& m);

    //l'operator[] emula il comportamento degli array stile C
    Lettura& operator[](int n);
    const Lettura& operator[] (int n) const;

    //il metodo aiuta ad evitare magic numbers (size è costante e non scelta dall'utente)
    int size() const { return NUM_LETTURE; }

    private:
    static const int NUM_LETTURE{17};
    Lettura elem[NUM_LETTURE];
};

//operator<<
std::ostream& operator<<(std::ostream& os, Misura m);

#endif //Misura_h