#ifndef MyVector_h
#define MyVector_h

class MyVector{
    public:
    class Invalid {};
    //costruttore di default
    MyVector();
    //costruttore
    MyVector(int s);
    //costruttore con initializer list
    MyVector(std::initializer_list<lettura[]> lst);
    //costruttore copia
    MyVector(const MyVector& a);
    //assegnamento copia
    MyVector& operator=(const MyVector& a);
    //costruttore move
    MyVector(MyVector&& a);
    //assegnamento move
    MyVector& operator=(MyVector&&);
    
    int size() const{ return sz; };
    lettura& operator[](int i);
    lettura operator[](int i) const;
    ~MyVector();
    
    //funzioni membro per la gestione elementi del vector
    lettura& at(int n);
    lettura at(int n) const;
    void push_back(double value);
    void pop_back();
    void reserve(int n);
    
    private:
    //inseriti valori di default
    int sz;
    int buffer_sz;
    // const int LETTURE_DIM{17};
    lettura *elem;
};

#endif // MyVector_h