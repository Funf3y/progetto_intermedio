#ifndef vector_h
#define vector_h

#include "../include/misura.h"

class MyVector{
    public:

    class Invalid {};

    //costruttore di default
    explicit MyVector();

    //costruttore
    explicit MyVector(int s);

    //costruttore con initializer list
    MyVector(std::initializer_list<Misura> lst);

    //costruttore copia
    MyVector(const MyVector& a);

    //assegnamento copia
    MyVector& operator=(const MyVector& a);

    //costruttore move
    MyVector(MyVector&& a);
    
    //assegnamento move
    MyVector& operator=(MyVector&&);
    
    int size() const;
    Misura& operator[](int i);
    Misura operator[](int i) const;
    ~MyVector();
    
    //funzioni membro per la gestione elementi del vector
    Misura& at(int n);
    Misura at(int n) const;
    void push_back(Misura value);
    void pop_back();
    void reserve(int n);
    
    private:
    //inseriti valori di default
    int sz;
    int buffer_sz;
    Misura *elem;
};

#endif