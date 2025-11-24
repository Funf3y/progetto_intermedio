#include <iostream>

#include "../include/my_vector.h"
#include "../include/inertial_driver.h"
#include "../include/misura.h"
#include "../include/lettura.h"

int main(){

    /*****TEST*****/

    std::cout << "0: per Misura e Lettura\n1: per Inertial Driver\n2: per conversione da array" <<std::endl;
    int scelta {0};

    std::cin >> scelta;

    if(scelta == 0){
        std::cout << "**************************************** TEST MISURA E LETTURA ****************************************" << std::endl;

        /*Costruttore di default delle misure*/
        //- Permette di testare:
        //- Costruttore di default (Misura)
        //- operator<< (Misura)
        Misura m1;
        std::cout << "STAMPA COSTRUTTORE DEFAULT" << std::endl;
        std::cout << m1 << std::endl;

        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        /*Costruttore con initializer list*/
        //Permette di testare:
        //- Costruttore con initializer list (Misura)
        //- operator<<
        //- operator[]
        Lettura l1; 
        l1.pitch_v = 12.4;
        l1.pitch_a = 78;
        l1.roll_v = 0.7; 
        l1.roll_a = 90; 
        l1.yaw_v = 12.0;
        l1.yaw_a = 20;

        Lettura l2; 
        l2.pitch_v = 62.4;
        l2.pitch_a = 89;
        l2.roll_v = 34.7; 
        l2.roll_a = 65; 
        l2.yaw_v = 1.8;
        l2.yaw_a = 76.2;

        std::initializer_list<Lettura> prove_initializer  = {l1, l2};
        Misura m_init_1 {prove_initializer};
        std::cout << "STAMPA COSTRUTTORE CON INITIALIZER" << std::endl;
        std::cout << m_init_1 << std::endl;

        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        /*Copia di una misura in un'altra*/
        //Permette di testare:
        //- Costruttore copia 
        //- operator = per la copia 
        //- operator<<
        m1 = m_init_1;
        std::cout << "PROVA DELLA COPIA" << std::endl;
        std::cout << m1 << std::endl;

        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        /*Operator [] in lettura*/
        //Permette di testare:
        //- operator [] in lettura 
        //- operator << con lettura
        std::cout << "LETTURA CON [3]" << std::endl; 
        Lettura l3 = m1[3];
        std::cout << l3;
        
        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        /*Operator [] in scrittura  */
        //Permette di testare:
        //- operator [] in scrittura 
        //- operator << con misura
        std::cout << "LETTURA E SCRITTURA CON [4]" << std::endl; 
        Lettura l4; 
        l4.pitch_v = 27.27;
        l4.pitch_a = 27.27;
        l4.roll_v = 27.27; 
        l4.roll_a = 27.27; 
        l4.yaw_v = 27.27;
        l4.yaw_a = 27.27;
        m1[4] = l4; 
        std::cout << m1 << std::endl;    
        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        /*inizializzazione con initializer list di dimensione > 17*/
        //Permette di testare:
        //- Costruttore con initializer list
        //- operator[]
        //- operator<<
        //- Funzione size() di Misura

        std::cout << "INIZIALIZZAZIONE CON INITIALIZER LIST TROPPO GRANDE (catch dell'errore)" << std::endl;
        try{
            std::initializer_list<Lettura> prove_initializer  = {l1, l2, l1, l2, l1, l1, l1, l1, l1, l1, l2, l2, l2, l2, l2, l2, l2, l2};
            Misura m_init {prove_initializer};
            std::cout << m_init << std::endl;
        }catch(Misura::Invalid){
            std::cout << "La inizializer list fornita ha troppi elementi" << std::endl; 
        }
    }
    else if (scelta == 1){
        std::cout << "\n**************************************** TEST INERTIAL DRIVER ****************************************\n" << std::endl;
        
        Lettura l1; 
        l1.pitch_v = 1;
        l1.pitch_a = 1;
        l1.roll_v = 1; 
        l1.roll_a = 1; 
        l1.yaw_v = 1;
        l1.yaw_a = 1;

        Lettura l2; 
        l2.pitch_v = 2;
        l2.pitch_a = 2;
        l2.roll_v = 2; 
        l2.roll_a = 2; 
        l2.yaw_v = 2;
        l2.yaw_a = 2;

        Misura m; 
        Misura m1 = {l1, l1};
        Misura m2 = {l2, l2, l2, l2}; 

        std::cout << "--OPERAZIONI CON INERTIAL DRIVER: costruttore di default" << std::endl;
        /*test del costruttore di defailt di initial driver*/
        //Permette di testare:
        //- Costruttore di default initial driver

        InertialDriver inert_driver_1; 

        /*test del push_back di inertial driver*/
        //Permette di testare:
        //- is_full di inertrial driver
        //- increment di inertial driver
        //- operator<<
        inert_driver_1.push_back(m1);
        std::cout << "PUSH BACK DI INERTIAL DRIVER" << std::endl;
        std::cout << "Stampa elemento appena inserito:" << std::endl << inert_driver_1 << std::endl;

      
        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;


        std::cout << "--OPERAZIONI CON INERTIAL DRIVER: costruttore con dimensione scelta" << std::endl;
        /*test del costruttore con buffer di dimensione decisa dal'utente di initial driver*/
        //Permette di testare:
        //- Costruttore con argomento la dimensione del buffer
        InertialDriver inert_driver_2 {3};
        
        
        /*test del push_back di inertial driver*/
        //Permette di testare:
        //- is_full di inertrial driver
        //- increment di inertial driver
        //- operator<<

        /*
        inert_driver_2.push_back(m2);
        std::cout << "PUSH BACK DI INERTIAL DRIVER" << std::endl;
        std::cout << "Stampa elemento appena inserito:" << std::endl << inert_driver_2 << std::endl;
        */

        /*test del get_reading di inertial driver*/
        /*
        std::cout << "GET READING DI INERTIAL DRIVER" << std::endl;
        std::cout << "Stampa prima lettura della misura appena inserita:" << std::endl;
        std::cout << inert_driver_2.get_reading(0) << std::endl;
        */

        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        /*test pop_front*/
        //Permette di testare:
        //- pop_front
        //- is_empty
        //- increment
        //- operator[] (myVector)
        //- lancio eccezione Invalid
        //- stampa di misura
        //Misura mis_rimossa = inert_driver_2.pop_front();
        
        std::cout << "Stampa elemento appena rimosso:" << std::endl << inert_driver_2.pop_front() << std::endl;
        std::cout << "quanti elementi sono contenuti: " << inert_driver_2.size() << std::endl;  
        try{
            //std::cout << "TEST eccezione per getReading di una lettura da Inertial driver vuoto" << std::endl; 
            //std::cout << "Stampa la prima lettura  di inertial_driver_1" << std::endl;
            //std::cout << inert_driver_1.get_reading(0) << std::endl;
            

        }catch(InertialDriver::Invalid){
            std::cout << "buffer vuoto"; 

        }
    
        //POPOLO inertial_driver_1
        //TEST sulla corretta sovrascrittura della prima misura e push back
        inert_driver_2.push_back(m);
        inert_driver_2.print_all_buffer();
        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        inert_driver_2.push_back(m1);
        inert_driver_2.print_all_buffer();

        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        inert_driver_2.push_back(m2);
        inert_driver_2.print_all_buffer();

        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        inert_driver_2.push_back(m2);
        inert_driver_2.print_all_buffer();
        
        std::cout << "quanti elementi sono contenuti: " << inert_driver_2.size() << std::endl;  



        std::cout << "Stampa prima lettura di inertial_driver_2" << std::endl;
        std::cout << inert_driver_2.get_reading(0) << std::endl;


        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "TEST della copia: inertial driver 1 = inertial driver 2" << std::endl;
        inert_driver_1 = inert_driver_2;
        inert_driver_1.print_all_buffer();


        std::cout << "Stampa prima lettura di inertial_driver_1" << std::endl;
        std::cout << inert_driver_1.get_reading(0) << std::endl;


        try{
            //std::cout << "TEST eccezione per getReading di una lettura fuori dal range" << std::endl; 
            //std::cout << "Stampa la lettura 18 di inertial_driver_1" << std::endl;
            //std::cout << inert_driver_1.get_reading(18) << std::endl;
            

        }catch(InertialDriver::Invalid){
            std::cout << "out of range"; 
        }
        



    }
    else if(scelta == 2){
        Lettura l1; 
        l1.pitch_v = 12.4;
        l1.pitch_a = 78;
        l1.roll_v = 0.7; 
        l1.roll_a = 90; 
        l1.yaw_v = 12.0;
        l1.yaw_a = 20;

        Lettura array17 [17] = {l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1};
        Misura m = array17;
        std::cout << "STAMPA MISURA DA CONVERSIONE CON ARRAY\n" << m << std::endl;

        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        Lettura array_lungo [18] = {l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1};
        m = array_lungo;
        std::cout << "STAMPA MISURA DA CONVERSIONE CON ARRAY (più grande del previsto)\n" << m << std::endl;

        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        Lettura array_corto [16] = {l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1, l1};
        m = array_corto;
        std::cout << "STAMPA MISURA DA CONVERSIONE CON ARRAY (più piccolo del previsto)\n" << m << std::endl;

        std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        InertialDriver indr {5};
        indr.push_back(m);
        std::cout << "STAMPA INERTIAL DRIVER DOPO INSERIMENTO DI ARRAY STILE C DI LETTURE (non di Misura)\n" << m << std::endl;
    }
    else{
        std::cout << "Termino il programma." << std::endl;
    }
}