#include <stdexcept>

#include "../include/misura.h"
#include "../include/lettura.h"

/*costruttori*/
//Policy: tutti i valori non forniti vengono assunti nulli. Se forniti valori extra, si verifica un errore.

//costruttore di default
Misura::Misura(){
    
    //creo una lettura di default da assegnare a tutte le 17 letture per una misurazione 
    Lettura l_default;
    l_default.pitch_v = 0;
    l_default.pitch_a = 0;
    l_default.roll_v = 0; 
    l_default.roll_a = 0; 
    l_default.yaw_v = 0;
    l_default.yaw_a = 0;


    for(int i = 0; i < NUM_LETTURE; i++){
        elem[i] = l_default;
    }
}
   
//costruttore con initializer list 
//si passano delle letture già prese  
Misura::Misura(std::initializer_list<Lettura> lst){
    if(lst.size() > NUM_LETTURE){
        throw  Invalid(); //giustificato dalla policy
    }

    Lettura l_default;
    l_default.pitch_v = 0;
    l_default.pitch_a = 0;
    l_default.roll_v = 0; 
    l_default.roll_a = 0; 
    l_default.yaw_v = 0;
    l_default.yaw_a = 0;

    for(int i = 0; i < NUM_LETTURE; ++i){
        
        if(i >= lst.size()){
            elem[i] = l_default; 
        }else{
            elem[i] = lst.begin()[i];
        }
    }
}

//costruttore copia
Misura::Misura(const Misura& m){
    for(int i = 0; i < NUM_LETTURE; ++i){
        elem[i] = m.elem[i];
    }
}

//assegnamento copia
Misura& Misura::operator=(const Misura& m){
    for(int i = 0; i < NUM_LETTURE; ++i){
        elem[i] = m.elem[i];
    }

    return *this;
}

//costruttore move
Misura::Misura(Misura&& m){
    for(int i = 0; i < NUM_LETTURE; ++i){
        elem[i] = m.elem[i];
    }
}

//assegnamento move
Misura& Misura::operator=(Misura&& m){
    for(int i = 0; i < NUM_LETTURE; ++i){
        elem[i] = m.elem[i];
    }
    return *this;
}

//operatore di accesso per scrittura
Lettura& Misura::operator[] (int n)
{
    if(n < 0 || n >= NUM_LETTURE)
    {
        throw std::out_of_range ("Misura fuori dal range (deve essere compresa tra 0 e 16)");
    }
    return elem[n];  //ritorna un riferimento modificabile
}

//operatore di accesso per lettura
const Lettura& Misura::operator[] (int n) const
{
    if(n < 0 || n >= NUM_LETTURE)
    {
        throw std::out_of_range ("Misura fuori dal range (deve essere compresa tra 0 e 16)");
    }
    return elem[n];    //ritorna un riferimento non modificabile
}

std::ostream& operator<<(std::ostream& os, Lettura l){
    os << "{yaw velocity: " << l.yaw_v << "; yaw acceleration: " << l.yaw_a << ";\t"
       << "pitch velocity: " << l.pitch_v << "; pitch acceleration: " << l.pitch_a << ";\t"
       << "roll velocity: " << l.roll_v << "; roll acceleration: " << l.roll_a << "}" << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& os, Misura m){
    os << "Misura [\n";

    for(int i = 0; i < m.size(); ++i){
       os << "Sensore " << i+1 << ":\t" << m[i];
    }
    os << "]";

    return os;
}