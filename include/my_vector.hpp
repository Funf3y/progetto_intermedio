#ifndef vector_hpp
#define vector_hpp

#include <iostream>
#include <stdexcept>

#include "my_vector.h"

constexpr int DEFAULT_SIZE{50};

//costruttore di default
template<typename T>
MyVector<T>::MyVector()
:sz{0}, buffer_sz{DEFAULT_SIZE}, elem{new T[DEFAULT_SIZE]}{}

//costruttore
template<typename T>
MyVector<T>::MyVector(int s)
:sz{s}, buffer_sz{s}, elem{new T[buffer_sz]}
{
    if(s < 0) { 
        throw Invalid(); 
    }
    else if(s==0) {
        elem = nullptr;
    }
}

//costruttore con inizializer list
template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> lst)
: sz{(int) lst.size()}, buffer_sz{(int) lst.size()}, elem{new T[buffer_sz]}
{
    std::copy(lst.begin(), lst.end(), elem);
}

//costruttore copia
template<typename T>
MyVector<T>::MyVector(const MyVector<T>& a)
:sz{a.sz}, buffer_sz{a.buffer_sz}, elem{new double[buffer_sz]}
{
    std::copy(a.elem, a.elem + sz, elem);
}

//assegnamento copia
template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& a){
    double* p = new double[a.buffer_sz];
    std::copy(a.elem, a.elem + a.sz, p);
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}

//costruttore move
template<typename T>
MyVector<T>::MyVector(MyVector<T>&& a)
: sz{a.sz}, buffer_sz{a.buffer_sz}, elem{a.elem}
{
    a.sz = 0;
    a.buffer_sz = 0;
    a.elem = nullptr;
}

//assegnamento move
template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& a)
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

//definizione spostata qui perché vietata nel .h
template<typename T>
int MyVector<T>::size() const{ return sz; }

template<typename T>
T& MyVector<T>::operator[](int i){
    return elem[i];
}

template<typename T>
T MyVector<T>::operator[](int i) const{
    return elem[i];
}

//distruttore
template<typename T>
MyVector<T>::~MyVector(){
    delete[] elem;
}

template<typename T>
T& MyVector<T>::at(int n){
    if(!(n < sz) || n < 0){ 
        throw std::out_of_range{"Out of range (index)"}; 
    }
    T& ref = *(elem + n);
    return ref;
}

template<typename T>
T MyVector<T>::at(int n) const{
    if(!(n < sz) || n < 0){ 
        throw std::out_of_range{"Out of range (index)"}; 
    }
    double& ref = *(elem + n);
    return ref;
}

template<typename T>
void MyVector<T>::push_back(T value){
    if(sz == buffer_sz){
        buffer_sz = 1.5 * buffer_sz + 1;
        T* p = new T[buffer_sz]; //il 1+ gestisce il caso in cui il vettore sia vuoto e buff_sz nulla
        std::copy(elem, elem + sz, p);
        delete[] elem;
        elem = p;
    }
    elem[sz] = value;
    ++sz;
}

template<typename T>
void MyVector<T>::pop_back(){
    //Nella documentazione viene indicato che in caso il vettore sia vuoto la funzione causa "undefined behavior".
    //Siccome non vengono effettuate specifiche nel testo dell'esercizio e siccome questo è *My*Vector,
    //ho deciso di farlo fallire silenziosamente in caso l'utente tentasse di eliminare un elemento da un vettore vuoto
    if(sz == 0){ return; }
    --sz;
}

template<typename T>
void MyVector<T>::reserve(int n){
    if(n <= buffer_sz){
        return;
    }
    buffer_sz = n;
    T* p = new T[buffer_sz];
    std::copy(elem, elem + sz, p);
    delete[] elem;
    elem = p;
}

#endif 