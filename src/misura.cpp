#include "../include/misura.h"
#include <stdexcept>

//costruttori

Misura::Misura(){
    
    //creo una lettura di default da assegnare a tutte le 17 letture peer una misurazione 
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
//si passano delle misure già prese  
Misura::Misura(std::initializer_list<Lettura> lst)
{
    //--> non si sa se la dimensione corrisponde => effettuo dei controlli 
    Lettura l_default;
    l_default.pitch_v = 0;
    l_default.pitch_a = 0;
    l_default.roll_v = 0; 
    l_default.roll_a = 0; 
    l_default.yaw_v = 0;
    l_default.yaw_a = 0;

    //è stata passata una serie di misure non consone al programma -> ERRORE 
    if(lst.size()> NUM_LETTURE){
        throw  Invalid(); 
    }

    for(int i = 0; i < NUM_LETTURE; ++i){
        elem[i] = lst.begin()[i];
        if(i >= lst.size()){
            elem[i] = l_default; 
        }
    }
}

//costruttore copia
Misura::Misura(const Misura& m){
    for(int i = 0; i < NUM_LETTURE; ++i){
        elem[i] = m.elem[i];
    }
}

//operatore di accesso per scrittura
Lettura& Misura::operator[] (int n)
{
    if(n<0 || n>=NUM_LETTURE)
    {
        throw std::out_of_range ("Misura fuori dal range (deve essere comresa tra 0 e 16)");
    }
    return elem[n];  
}

//operatore di accesso per lettura
onst Lettura& Misura::operator[] (int n) const
{
    if(n<0 || n>=NUM_LETTURE)
    {
        throw std::out_of_range ("Misura fuori dal range (deve essere comresa tra 0 e 16)");
    }
    return elem[n];    
}//ritorna un riferimento non modifìicabile