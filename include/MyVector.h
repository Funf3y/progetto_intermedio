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
    MyVector(std::initializer_list<double> lst);
    //costruttore copia
    MyVector(const MyVector& a);
    //assegnamento copia
    MyVector& operator=(const MyVector& a);
    //costruttore move
    MyVector(MyVector&& a);
    //assegnamento move
    MyVector& operator=(MyVector&&);
    
    int size() const{ return sz; };
    //int b_size() const {return buffer_sz; } //metodo implementato solo per testare la correttezza di reserve()
    double& operator[](int i);
    double operator[](int i) const;
    ~MyVector();
    
    //funzioni membro per la gestione elementi del vector
    double& at(int n);
    double at(int n) const;
    void push_back(double value);
    void pop_back();
    void reserve(int n);
    
    private:
    //inseriti valori di default
    int sz;
    int buffer_sz;
    double *elem;
};

#endif //MyVector_h