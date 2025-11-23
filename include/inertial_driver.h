#ifndef InertialDriver_h
#define InertialDriver_h

#include <iostream>

#include "my_vector.h"
#include "lettura.h"
#include "misura.h"

class InertialDriver{
    public:

    class Invalid {};

    //costruttore di default
    //di default la dimensione viene scelta dal programmatore
    InertialDriver();

    //costruttore con parametri
    //dimensione del buffer decisa dall'utente
    explicit InertialDriver(int buffer_dim);


    //distruttore
    ~InertialDriver();
    
    /*funzioni per accedere all'interfaccia*/
    
    //push_back
    //accetta un array stile C contenente una misura e la memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno)
    void push_back(Misura m);

    //pop_front
    //fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer
    Misura pop_front();

    //clear_buffer
    //elimina (senza restituirle) tutte le misure salvate
    void clear_buffer();

    //get_reading
    //accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer
    Lettura get_reading(int index);

    /*funzioni che rappresentano lo stato del buffer*/

    //verifica se il buffer è vuoto
    bool is_empty(); 

    //verifica se il buffer è pieno => devo iniziare a sovrascrivere 
    bool is_full();

    int size();

    /*getter*/
    Misura getBack();

    private:
    //dati membro
    MyVector buffer; //buffer di misure
    const int BUFFER_DIM {3}; //dimensione scelta arbitrariamente (per ora 3 per fare test, poi TODO cambia il numero)
    int front {0}; //indice dell'elemento più vecchio presente nel buffer
    int back {0}; //indice dell'elemento più nuovo presente nel buffer
    

};

//operator<<
//stampa a schermo l’ultima misura salvata (ma non la rimuove dal buffer)
std::ostream& operator<<(std::ostream& os, InertialDriver indr);

/*FUNZIONI HELPER*/

//incrementa gli indici 
int increment(int index, int buffer_dim);

//stampa l'intero buffer
//TODO: se avanza tempo
//void stampa(InertialDriver indr);

#endif //InertialDriver_h