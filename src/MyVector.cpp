/******************************************************************************************
4. Implementare la classe MyVector, analoga alla classe vector discussa a lezione, che
rappresenta vettori di double di lunghezza decisa in fase di costruzione (e non
modificabile in seguito). Il buffer dove sono salvati i dati di MyVector deve essere allocato
dinamicamente, poiché i dati da salvare potrebbero essere numerosi. Includere nella
classe:
a. un dato membro int che contiene la lunghezza del vettore;
b. un costruttore che accetta un int che indica la lunghezza del vettore da costruire;
c. l’overloading dell’operatore [] - sia in versione const che non const;
d. le funzioni safe_set() e safe_get() che permettono l’accesso agli elementi
del vettore effettuando il controllo di accesso entro i limiti del vettore;
e. il distruttore.

Implementare la classe MyVector che gestisce vettori di elementi double in maniera analoga a
std::vector. I dati devono essere gestiti tramite allocazione dinamica della memoria. Il buffer di
memoria è progettato per essere più grande rispetto all’effettivo numero di elementi (come negli
array parzialmente riempiti). È quindi necessario che MyVector tenga conto di due valori: il
numero di elementi effettivamente salvati e il massimo numero di elementi gestibile con il buffer
corrente. La richiesta di aggiungere elementi al buffer oltre lo spazio disponibile comporta la
riallocazione di un buffer più grande, e la copia degli elementi nel nuovo buffer. È perciò importante
adottare una buona politica di gestione della memoria, poiché le riallocazioni sono
computazionalmente molto pesanti.
Devono essere presenti le seguenti funzioni membro:
● Le operazioni essenziali illustrate a lezione;
● Accesso ai membri tramite il doppio overloading dell’operator[];
● Accesso con boundary check tramite la funzione at() (si veda la corrispondente funzione
STL: https://www.cplusplus.com/reference/vector/vector/at/), con opportuna gestione di
overloading (per lettura/scrittura) e dei casi di out of bound (eccezione);
● Funzione push_back() che aggiunge un elemento alla fine;
● Funzione pop_back() che rimuove l’ultimo elemento;
● Funzione reserve() (si veda la corrispondente funzione STL:
https://www.cplusplus.com/reference/vector/vector/reserve/), che impone una dimensione
minima del buffer (laddove la dimensinoe del buffer corrente è maggiore del valore passato
da reserve(), non fa nulla).
******************************************************************************************/

#include <iostream>
#include <stdexcept>
#include "MyVector.h"
constexpr int DEFAULT_SIZE{50};

//costruttore di default
MyVector::MyVector()
:sz{0}, buffer_sz{DEFAULT_SIZE}, elem{new double[DEFAULT_SIZE]}{}
//costruttore
MyVector::MyVector(int s)
:sz{s}, buffer_sz{s}, elem{new double[buffer_sz]}
{
    if(s < 0) { 
        throw Invalid(); 
    }
    else if(s==0) {
        elem = nullptr;
    }
}

//costruttore con inizializer list
MyVector::MyVector(std::initializer_list<double> lst)
: sz{(int) lst.size()}, buffer_sz{(int) lst.size()}, elem{new double[buffer_sz]}
{
    std::copy(lst.begin(), lst.end(), elem);
}

//costruttore copia
MyVector::MyVector(const MyVector& a)
:sz{a.sz}, buffer_sz{a.buffer_sz}, elem{new double[buffer_sz]}
{
    std::copy(a.elem, a.elem + sz, elem);
}

//assegnamento copia
MyVector& MyVector::operator=(const MyVector& a){
    double* p = new double[a.buffer_sz];
    std::copy(a.elem, a.elem + a.sz, p);
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}

//costruttore move
MyVector::MyVector(MyVector&& a)
: sz{a.sz}, buffer_sz{a.buffer_sz}, elem{a.elem}
{
    a.sz = 0;
    a.buffer_sz = 0;
    a.elem = nullptr;
}

//assegnamento move
MyVector& MyVector::operator=(MyVector&& a)
{
    delete[] elem;
    elem = a.elem;
    sz = a.sz;
    buffer_sz = a.buffer_sz;
    a.elem = nullptr;
    a.sz = 0;
    a.buffer_sz = 0;
    return *this;
}

double& MyVector::operator[](int i){
    return elem[i];
}

double MyVector::operator[](int i) const{
    return elem[i];
}

//distruttore
MyVector::~MyVector(){
    delete[] elem;
}

double& MyVector::at(int n){
    if(!(n < sz) || n < 0){ 
        throw std::out_of_range{"Out of range (index)"}; 
    }
    double& ref = *(elem + n);
    return ref;
}

double MyVector::at(int n) const{
    if(!(n < sz) || n < 0){ 
        throw std::out_of_range{"Out of range (index)"}; 
    }
    double& ref = *(elem + n);
    return ref;
}

void MyVector::push_back(double value){
    if(sz == buffer_sz){
        buffer_sz = 1.5 * buffer_sz + 1;
        double* p = new double[buffer_sz]; //il 1+ gestisce il caso in cui il vettore sia vuoto e buff_sz nulla
        std::copy(elem, elem + sz, p);
        delete[] elem;
        elem = p;
    }
    elem[sz] = value;
    ++sz;
}

void MyVector::pop_back(){
    //Nella documentazione viene indicato che in caso il vettore sia vuoto la funzione causa "undefined behavior".
    //Siccome non vengono effettuate specifiche nel testo dell'esercizio e siccome questo è *My*Vector,
    //ho deciso di farlo fallire silenziosamente in caso l'utente tentasse di eliminare un elemento da un vettore vuoto
    if(sz == 0){ return; }
    --sz;
}

void MyVector::reserve(int n){
    if(n <= buffer_sz){
        return;
    }
    buffer_sz = n;
    double* p = new double[buffer_sz];
    std::copy(elem, elem + sz, p);
    delete[] elem;
    elem = p;
}