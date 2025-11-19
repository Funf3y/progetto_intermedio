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
        buffer_sz = 1.5 * buffer_sz + 1; //il 1+ gestisce il caso in cui il vettore sia vuoto e buff_sz nulla
        double* p = new double[buffer_sz]; 
        std::copy(elem, elem + sz, p);
        delete[] elem;
        elem = p;
    }
    elem[sz] = value;
    ++sz;
}

void MyVector::pop_back(){
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