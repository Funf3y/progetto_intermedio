#ifndef Misura_h
#define Misura_h

#include <iostream>

#include "Lettura.h"

class Misura{
    public:

    //costruttori

    Misura();

    Misura(std::initializer_list<lettura> lst);

    //copia e move?

    lettura& operator[](int n);
    const lettura& operator[] (int n) const;

    //erano presenti nelle slides, ma a cosa servono esattamente?
    /*lettura* data(){ return elem; }
    const lettura* data() const { return elem; }
    */

    int size() const { return NUM_LETTURE; }

    private:
    static const int NUM_LETTURE{17};
    lettura elem[NUM_LETTURE];
};

//operator<<
std::ostream& operator<<(std::ostream& os, Misura m);

#endif //Misura_h