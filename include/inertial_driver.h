#ifndef InertialDriver_h
#define InertialDriver_h

#include <iostream>

#include "my_vector.h"
#include "lettura.h"
#include "misura.h"

class InertialDriver{
    public:

    //costruttore di default
    //di default la dimensione viene scelta dal programmatore
    InertialDriver();

    //costruttori con parametri
    //dimensione del buffer decisa dall'utente
    explicit InertialDriver(int buffer_dim);


    /*funzioni per accedere all'interfaccia*/
    
    //push_back
    //accetta un array stile C contenente una misura e la memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno)
    void push_back(Lettura misura[]);

    //pop_front
    //fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer
    Misura pop_front();

    //clear_buffer
    //elimina (senza restituirle) tutte le misure salvate
    void clear_buffer();

    //get_reading
    //accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer
    //lettura* get_reading(int index); //da risolvere

    private:
    //dati membro
    MyVector<Misura> buffer; //buffer di misure
    const int BUFFER_DIM; //dimensione scelta arbitrariamente (per ora 3 per fare test)
    int front{0}; //indice dell'elemento più vecchio presente nel buffer
    int back{0}; //indice dell'elemento più nuovo presente nel buffer

};

//operator<<
std::ostream& operator<<(std::ostream& os, InertialDriver indr);

#endif //InertialDriver_h