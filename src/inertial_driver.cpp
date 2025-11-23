#include <iostream>

#include "../include/inertial_driver.h"
#include "../include/misura.h"
#include "../include/lettura.h"

//costruttore di default
InertialDriver::InertialDriver() 
: buffer(BUFFER_DIM), front{0}, back{0} {}

InertialDriver::~InertialDriver(){}

//is_empty
bool InertialDriver::is_empty(){
    if(front == back){
        return true; 
    }
    return false; 
}

//is_full
bool InertialDriver::is_full(){
    if(increment(back) == front){
        return true; 
    }
    return false; 
}

//incrementa un indice (front o back) di uno 
//se raggiunge la fine dello "spazio" ri-inizia il giro 
int InertialDriver::increment(int index){
    return (index +1)%BUFFER_DIM;
}

//push_back
//accetta un array stile C contenente una misura e la memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno)
/*void InertialDriver::push_back(Misura m){
    
    //per debug --> poi si può togliere 
    if(is_empty()){
        buffer.push_back(m);
        increment(back); 
        
        std::cout << "era vuoto";
    }
    buffer.push_back(m);
    increment(back);

    if(is_full()){
        //NOTA X SG E GB
        //non saprei come scrivere 

    }
}*/

//pop_front
//fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer
///lettura* InertialDriver::pop_front(){ //da risolvere in un secondo momento

//}


//clear_buffer
//elimina (senza restituirle) tutte le misure salvate
void InertialDriver::clear_buffer(){
    front = 0;
    back = 0;
}

//get_reading
//accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer
/*Lettura get_reading(int index){
    
}*/