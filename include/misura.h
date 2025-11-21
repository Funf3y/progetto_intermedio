#ifndef Misura_h
#define Misura_h

#include <iostream>

#include "lettura.h"

class Misura{
    public:

    //costruttori

    Misura();

    //conversione esplicita tra array stile C di letture e `misura`
    Misura(Lettura mis[]);

    Misura(std::initializer_list<Lettura> lst);

    /*copia e move*/

    Misura(const Misura& a);
    //assegnamento copia
    Misura& operator=(const Misura& a);
    //costruttore move
    Misura(Misura&& a);
    //assegnamento move
    Misura& operator=(Misura&&);

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