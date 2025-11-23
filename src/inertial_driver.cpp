#include <iostream>

#include "../include/inertial_driver.h"
#include "../include/misura.h"
#include "../include/lettura.h"

/*COSTRUTTORI*/

//costruttore di default
InertialDriver::InertialDriver() 
: buffer(BUFFER_DIM), front{0}, back{0} {}

//costruttore con dimensione del buffer scelta dall'utente 
InertialDriver::InertialDriver(int buffer_dim)
: buffer(buffer_dim), front{0}, back{0} {}

//TODO: pensa se aggiungere copia e move

//distruttore
//TODO
InertialDriver::~InertialDriver(){}

bool InertialDriver::is_empty(){
    if(front == back){
        return true; 
    }
    return false; 
}

bool InertialDriver::is_full(){
    if(increment(back, BUFFER_DIM) == front){
        return true; 
    }
    return false; 
}

int InertialDriver::size(){
    if(back < front){
        return (BUFFER_DIM - front) + back + 1;
    }
    return (back-front);
}

//TODO: se avanza tempo, implementa per bene la stampa dell'intero buffer
/*void stampa(InertialDriver indr){
    if(back < front){

    }
    else{
        for(int i = front; indr.size(); ++i){
            std::cout << "nasdkfjh";
        }
    }
}*/

//incrementa un indice (front o back) di uno 
//se raggiunge la fine dello "spazio" ricomincia il giro 
int increment(int index, int buffer_dim){
    return (index + 1) % buffer_dim;
}

Misura InertialDriver::getBack(){
    return buffer[back];
}

//accetta un array stile C contenente una misura e la memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno)
void InertialDriver::push_back(Misura m){
    if(is_full()){
        //se il buffer è pieno -> sovrascrivo la misura più vecchia 
        buffer[front] = m; //sovrascrittura del front (misura più vecchia)
        back = increment(back, BUFFER_DIM); //incremento back -> va nella pos del vecchio front (ultima misura inserita)
        front = increment(front, BUFFER_DIM); //incremento front -> va nella nuova misura più vecchia 

    }else{
        //std::cout << "else di InertialDriver::push:back" << std::endl;
        //inserimento normale 
        back = increment(back, BUFFER_DIM); 
        buffer[back] = m; 
    }

}

//fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer
Misura InertialDriver::pop_front(){
    if(is_empty()){
        throw Invalid(); //non è possibile rimuovere un elemento se è vuoto
    }

    Misura m = buffer[front];
    front = increment(front, BUFFER_DIM); //rimozione misura più vecchia
    return m;
}    

//elimina (senza restituirle) tutte le misure salvate
void InertialDriver::clear_buffer(){
    front = 0;
    back = 0;
}

//accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer
Lettura InertialDriver::get_reading(int index){
    Lettura l;
    return l;
}

std::ostream& operator<<(std::ostream& os, InertialDriver indr){
    return os << indr.getBack();
}