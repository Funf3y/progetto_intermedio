#ifndef InertialDriver_h
#define InertialDriver_h

#include <iostream>

#include "my_vector.h"
#include "lettura.h"
#include "misura.h"

class InertialDriver{
    public:

    //Classe creata per riportare errori
    class Invalid {};

    /*COSTRUTTORI*/

    //costruttore di default
    //di default la dimensione viene scelta dal programmatore
    InertialDriver();

    //costruttore con parametri
    //dimensione del buffer decisa dall'utente
    explicit InertialDriver(int buffer_dim);

    //costruttore copia
    InertialDriver(const InertialDriver& indr);

    //assegnamento copia
    //copia tutte le misure di un Inertial Driver su un altro (a partire dal primo slot del nuovo buffer), 
    //se lo spazio non è sufficiente: errore
    InertialDriver& operator=(const InertialDriver& indr);

    //vieto esplicitamente operazioni move
    InertialDriver(InertialDriver&& indr) = delete;

    InertialDriver& operator=(InertialDriver&& indr) = delete;

    //non serve scrivere il distruttore perché viene chiamato in automatico il distruttore di MyVector, che si occupa di liberare la memoria del buffer
    
    /*FUNZIONI DI ACCESSO ALL'OGGETTO (secondo le modalità specificate)*/
    
    //accetta un array stile C contenente una misura e la memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno)
    void push_back(Misura m);

    //fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer
    //(TODO: quando si richiede un array stile C, la conversione funziona, ma quando lo si restituisce? Guarda forum)
    Misura pop_front();

    //elimina (senza restituirle) tutte le misure salvate
    void clear_buffer();

    //accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer
    Lettura get_reading(int index);

    /*RAPPRESENTAZIONI STATO DELL'OGGETTO*/

    //verifica se il buffer è vuoto
    bool is_empty(); 

    //verifica se il buffer è pieno
    bool is_full();

    //restituisce il numero di elementi
    int size() const;

    //restituisce l'ultima misura inserita, senza permettere di modificarla
    const Misura& get_back();

    //stampa tutte le misure inserite nel buffer, nell'ordine di inserimento
    void print_all_buffer();


    private:

    MyVector buffer; //buffer di misure
    const int BUFFER_DIM; //numero massimo di misure contenibili nel buffer
    int front; //indice dell'elemento più vecchio presente nel buffer
    int back; //indice dell'elemento più nuovo presente nel buffer
    

};

/*FUNZIONI HELPER*/

//stampa a schermo l’ultima misura salvata (ma non la rimuove dal buffer)
std::ostream& operator<<(std::ostream& os, InertialDriver indr);

//incrementa l'indice fornito in base alla dimensione del buffer fornita 
int increment(int index, int buffer_dim);

#endif //InertialDriver_h