/******************************************************************************************
Implementare la classe MyVector vista nel laboratorio 4 rendendo generici gli elementi contenuti,
il che significa sostituire il double con un tipo generico T utilizzando i template. Tutte le funzioni
richieste nel laboratorio 4 devono essere aggiornate per tenere conto del template.
È obbligatorio implementare tutte le funzioni membro esternamente alla classe, quindi le
in-class definition sono vietate. È inoltre obbligatorio indicare prima i membri public, poi
quelli private.
******************************************************************************************/
#ifndef vector_h
#define vector_h

template<typename T>
class MyVector{
    public:
    class Invalid {};
    //costruttore di default
    explicit MyVector();
    //costruttore
    explicit MyVector(int s);
    //costruttore con initializer list
    MyVector(std::initializer_list<double> lst);
    //costruttore copia
    MyVector(const MyVector& a);
    //assegnamento copia
    MyVector& operator=(const MyVector& a);
    //costruttore move
    MyVector(MyVector&& a);
    //assegnamento move
    MyVector& operator=(MyVector&&);
    
    int size() const;
    T& operator[](int i);
    T operator[](int i) const;
    ~MyVector();
    
    //funzioni membro per la gestione elementi del vector
    T& at(int n);
    T at(int n) const;
    void push_back(T value);
    void pop_back();
    void reserve(int n);
    
    private:
    //inseriti valori di default
    int sz;
    int buffer_sz;
    T *elem;
};

#include "MyVector.hpp"
#endif 