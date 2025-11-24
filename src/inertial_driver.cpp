#include <iostream>

#include "../include/inertial_driver.h"
#include "../include/misura.h"
#include "../include/lettura.h"

/*COSTRUTTORI*/

//costruttore di default
const int DEFAULT_DIM {4};
InertialDriver::InertialDriver() 
: BUFFER_DIM{DEFAULT_DIM}, buffer(DEFAULT_DIM), front{0}, back{0} {}

//costruttore con dimensione del buffer scelta dall'utente 
InertialDriver::InertialDriver(int buffer_dim)
: BUFFER_DIM {buffer_dim + 1}, buffer(buffer_dim + 1), front{0}, back{0} {} //il +1 è necessario per poter come abbiamo studiato e definito un array gestito con politica circolare

//costruttore copia
InertialDriver::InertialDriver(const InertialDriver& indr)
:BUFFER_DIM{indr.BUFFER_DIM}, buffer{indr.buffer}, front {indr.front}, back {indr.back}{ }

//assegnamento copia
//copia tutte le misure di un Inertial Driver su un altro, se lo spazio non è sufficiente: errore
InertialDriver& InertialDriver::operator=(const InertialDriver& indr){
    if(BUFFER_DIM < indr.BUFFER_DIM){
        throw Invalid(); //policy: non si possono copiare Inertial Driver in altri di dimensioni più piccole, solo >=
    }

    if(indr.back < indr.front){
        int j = 0; //indice buffer dove sto copiando
        for(int i = indr.front; i < indr.BUFFER_DIM; ++i){
            buffer[j] = indr.buffer[i];
            ++j;
        }
        for(int i = 0; i < indr.back; ++i){
            buffer[j] = indr.buffer[i];
            ++j;
        }

        front = 0;
        back = (indr.BUFFER_DIM - indr.front) + indr.back;
    }
    else{
        for(int i = front; i < back; ++i){
            buffer[i] = indr.buffer[i];
        }
        front = indr.front;
        back = indr.back;
    }
    //BUFFER_DIM non può cambiare: è costante
    return *this;
}

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
        return (BUFFER_DIM - front) + back;
    }
    return (back-front);
}

//incrementa un indice (front o back) di uno 
//se raggiunge la fine dello "spazio" ricomincia il giro 
int increment(int index, int buffer_dim){
    return (index + 1) % buffer_dim;
}

const Misura& InertialDriver::get_back(){
    int index = (back - 1) % BUFFER_DIM;
    return buffer[index];
}

//accetta un array stile C contenente una misura e la memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno)
void InertialDriver::push_back(Misura m){
    
    //std::cout << "front prima: " << front <<"; back prima: " << back << std::endl;
    
    if(is_full()){
        //se il buffer è pieno -> sovrascrivo la misura più vecchia 
        buffer[back] = m; //sovrascrittura del front (misura più vecchia)
        back = increment(back, BUFFER_DIM); //incremento back -> va nella pos del vecchio front (ultima misura inserita)
        front = increment(front, BUFFER_DIM); //incremento front -> va nella nuova misura più vecchia 

    }else{
        //std::cout << "else di InertialDriver::push:back" << std::endl;
        //inserimento normale  
        buffer[back] = m; 
        back = increment(back, BUFFER_DIM);
    }

    //std::cout << "front dopo: " << front <<"; back dopo: " << back << std::endl;

}

//fornisce in output un array stile C contenente la misura più vecchia e la rimuove dal buffer
Misura InertialDriver::pop_front(){
    if(is_empty()){
        throw Invalid(); //non è possibile rimuovere un elemento se è vuoto
    }

    Misura m = buffer[front];
    //std::cout << "----> PROVA COUT DENTRO POP_FRONT\n" << buffer[front] << std::endl; 

    front = increment(front, BUFFER_DIM); //rimozione misura più vecchia
    return m;
}    

//elimina (senza restituirle) tutte le misure salvate
void InertialDriver::clear_buffer(){
    front = 0;
    back = 0;
}

//accetta un numero tra 0 e 16 e ritorna la corrispondente lettura della misura più recente, senza cancellarla dal buffer
Lettura InertialDriver::get_reading(int reading){
    Misura m;
    if(is_empty()){
        throw Invalid(); //non è possibile leggere un elemento se è vuoto
    }

    if(reading < 0 || reading >= m.size()){
        throw std::out_of_range ("Misura fuori dal range (deve essere compresa tra 0 e 16)");
    }

    int index = (back - 1 + BUFFER_DIM) % BUFFER_DIM;
    m = buffer[index];
    
    Lettura l = m[reading];

    return l;
}

void InertialDriver::print_all_buffer(){
    std::cout << "Inertial driver[ " << std::endl; 

    if(back < front){
        //int j = 0;
        for(int i = front; i < BUFFER_DIM; ++i){
            std::cout << "Indice " << /*j*/i<< ": " << buffer[i] << std::endl; 
            //++j;
        }
        for(int i = 0; i < back; ++i){
            std::cout << "Indice " << /*j*/i<< ": " << buffer[i] << std::endl; 
            //++j;
        }
    }
    else{
        //int j = 0;
        for(int i = front; i < back; ++i){
            std::cout << "Indice " << /*j*/i<< ": " << buffer[i] << std::endl; 
            //++j;
        }
    }
   std::cout << "] " << std::endl; 


}

std::ostream& operator<<(std::ostream& os, InertialDriver indr){
    return os << indr.get_back();
}