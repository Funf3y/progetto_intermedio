#ifndef Misura_h
#define Misura_h

#include <iostream>

#include "lettura.h"

class Misura{
    public:

    //Classe creata per riportare errori
    class Invalid {};

    //costruttore di default
    Misura();

    //costruttore con initializer list
    Misura(std::initializer_list<Lettura> lst);

    //conversione da array di Lettura a Misura
    Misura(Lettura* m);

    //costruttore copia
    Misura(const Misura& m);

    //assegnamento copia
    Misura& operator=(const Misura& m);

    //costruttore move
    Misura(Misura&& m);

    //assegnamento move
    Misura& operator=(Misura&& m);

    //l'operator[] emula il comportamento degli array stile C (con vontrollo sull'indice)
    Lettura& operator[](int index);
    const Lettura& operator[] (int index) const;

    //permette di evitare magic numbers (size è costante e non scelta dall'utente)
    int size() const { return NUM_LETTURE; }

    private:
    static const int NUM_LETTURE {17};
    Lettura elem[NUM_LETTURE];
};

//operator<< per Misura
std::ostream& operator<<(std::ostream& os, Misura m);

//operator<<  per Lettura
std::ostream& operator<<(std::ostream& os, Lettura l);

#endif //Misura_h