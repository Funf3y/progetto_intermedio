#ifndef InertialDriver_h
#define InertialDriver_h

#include <iostream>

#include "MyVector.h"
#include "Lettura.h"


class InertialDriver{
    public:

    //funzioni per accedere all'interfaccia
    
    //push_back
    //accetta un array stile C contenente una misura e la memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno)
    void push_back(lettura misura[]);

    //pop_front
    //fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer
    lettura* pop_front();

    //clear_buffer
    //elimina (senza restituirle) tutte le misure salvate
    void clear_buffer();

    //get_reading
    //accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer
    //lettura* get_reading(int index); //da risolvere

    private:
    //dati membro
    static const int DIM_ARRAY {17}; //numero di letture di una misura
    MyVector<lettura[DIM_ARRAY]> buffer; //buffer di misure
    const int BUFFER_DIM{3}; //dimensione scelta arbitrariamente (per ora 3 per fare test)
    int front{0}; //indice dell'elemento più vecchio presente nel buffer
    int back{0}; //indice dell'elemento più nuovo presente nel buffer

};

//operator<<
std::ostream& operator<<(std::ostream& os, InertialDriver indr);

#endif //InertialDriver_h