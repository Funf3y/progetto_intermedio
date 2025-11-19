#include "../include/InertialDriver.h"
#include "../include/Lettura.h"
#include <iostream>

//push_back
//accetta un array stile C contenente una misura e la memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno)
void InertialDriver::push_back(lettura misura[]){

}

//pop_front
//fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer
///lettura* InertialDriver::pop_front(){ //da risolvere in un secondo momento

//}


//clear_buffer
//elimina (senza restituirle) tutte le misure salvate
void InertialDriver::clear_buffer(){

}

//get_reading
//accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer
lettura get_reading(int index){
    
}