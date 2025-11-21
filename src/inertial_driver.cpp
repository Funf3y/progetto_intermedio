#include <iostream>

#include "../include/inertial_driver.h"
#include "../include/misura.h"
#include "../include/lettura.h"

//costruttore
/*InertialDriver::InertialDriver() : buffer{BUFFER_DIM}, front{0}, back{0} 
{

}*/



//push_back
//accetta un array stile C contenente una misura e la memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno)
void InertialDriver::push_back(Lettura Misura[]){

}

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
Lettura get_reading(int index){
    
}