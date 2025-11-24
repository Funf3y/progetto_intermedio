#include <iostream>

#include "../include/my_vector.h"
#include "../include/inertial_driver.h"
#include "../include/misura.h"
#include "../include/lettura.h"

int main(){

    /*****TEST*****/

    std::cout << "1: per Misura e Lettura;\n2: per Inertial Driver;\n3: per conversione da array;\n9: per tutti i test.\n0: per terminare." <<std::endl;
    int scelta {9};
    while(scelta != 0){
        std::cin >> scelta;

        if(scelta == 1 || scelta == 9){
            std::cout << "**************************************** TEST MISURA E LETTURA ****************************************" << std::endl;

            /*Costruttore di default delle misure*/
            //- Permette di testare:
            //- Costruttore di default
            //- operator<<
            Misura m1;
            std::cout << "STAMPA COSTRUTTORE DEFAULT" << std::endl;
            std::cout << m1 << std::endl;

            std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

            /*Costruttore con initializer list*/
            //Permette di testare:
            //- Costruttore con initializer list
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
            //- operator= per la copia 
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
        if (scelta == 2 || scelta == 9){
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

            /*Costruttore di default*/
            //- Permette di testare:
            //- Costruttore di default
            //- size()
            std::cout << "STAMPA COSTRUTTORE DEFAULT" << std::endl;
            InertialDriver inert_driver_1; 
            std::cout << "Dimensione con construttore di default (0 perché nessun elemento è stato inserito): " << inert_driver_1.size() << std::endl;

            std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

            /*test del push_back di inertial driver*/
            //Permette di testare:
            //- push_back
            //- is_full di inertrial driver
            //- increment di inertial driver
            //- operator<<
            inert_driver_1.push_back(m1);
            std::cout << "PUSH BACK" << std::endl;
            std::cout << "Stampa elemento appena inserito:" << std::endl << inert_driver_1 << std::endl;

            std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

            /*test del costruttore con buffer di dimensione decisa dal'utente di initial driver*/
            //Permette di testare:
            //- Costruttore con argomento la dimensione del buffer
            InertialDriver inert_driver_2 {3};
            std::cout << "STAMPA COSTRUTTORE CON PARAMETRO" << std::endl;
            std::cout << "Dimensione con construttore di default (0 perché nessun elemento è stato inserito): " << inert_driver_2.size() << std::endl;

            std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
            
            //Popolo inert_driver_2
            inert_driver_2.push_back(m);
            inert_driver_2.push_back(m1);
            inert_driver_2.push_back(m2);
            inert_driver_2.push_back(m2);

            /*test del get_reading di inertial driver*/
            //Permette di testare:
            //- is_empty()
            std::cout << "GET READING DI INERTIAL DRIVER" << std::endl;
            std::cout << "Stampa prima lettura della misura appena inserita:" << inert_driver_2.get_reading(0) << std::endl;
            

            std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

            /*test pop_front*/
            //Permette di testare:
            //- pop_front
            //- increment
            //- operator[] (myVector)
            //- stampa di misura
            Misura mis_rimossa = inert_driver_2.pop_front();

            std::cout << "GET READING DI INERTIAL DRIVER" << std::endl;
            
            std::cout << "Stampa elemento appena rimosso:" << std::endl << mis_rimossa << std::endl;
            std::cout << "Quanti elementi sono contenuti: " << inert_driver_2.size() << std::endl;  

            std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

            std::cout << "CLEAR BUFFER" << std::endl;
            inert_driver_2.clear_buffer();
            std::cout << "Quanti elementi sono contenuti: " << inert_driver_2.size() << std::endl; 

            std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

            try{

                /*test pop_front*/
                //-Permette di testare:
                //- is_empty
                //- lancio eccezione invalid
                std::cout << "GET READING SU INERTIAL DRIVER VUOTO (test eccezione)" << std::endl;
                std::cout << "Se Inertial Driver non fosse vuoto stamperei una Lettura:" << inert_driver_1.get_reading(0) << std::endl;

                std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

            }catch(InertialDriver::Invalid){
                std::cout << "L'Inertial Driver fornito è vuoto"; 
                std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
            }
        
            //POPOLO inertial_driver_1
            //TEST sulla corretta sovrascrittura della prima misura e push back

            std::cout << "Stampa di tutto il buffer dopo ogni push_back, per quattro push back (buffer di size 3)" << std::endl;

            inert_driver_2.push_back(m);
            inert_driver_2.print_all_buffer();
            
            inert_driver_2.push_back(m1);
            inert_driver_2.print_all_buffer();

            inert_driver_2.push_back(m2);
            inert_driver_2.print_all_buffer();

            inert_driver_2.push_back(m2);
            inert_driver_2.print_all_buffer();
            
            std::cout << "Elementi sono contenuti: " << inert_driver_2.size() << std::endl;  

            std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
            
            /*test assegnamento copia*/
            std::cout << "ASSEGNAMENTO COPIA" << std::endl;
            inert_driver_1 = inert_driver_2;
            std::cout << "Stampa primo Inertial Driver, nel quale è stato copiato il secondo" << std::endl;
            inert_driver_1.print_all_buffer();

            std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
            
            /*test costruttore copia*/
            std::cout << "COSTRUTTORE COPIA" << std::endl;
            InertialDriver inert_driver_3 = inert_driver_2;
            std::cout << "Stampa Inertial Driver creato usando costruttore copia" << std::endl;
            inert_driver_3.print_all_buffer();

            std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;

        }
        if(scelta == 3 || scelta == 9){
            std::cout << "**************************************** TEST CONVERSIONE DA ARRAY DI LETTURE A MISURA ****************************************" << std::endl;
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
    }
    
    std::cout << "Termino il programma." << std::endl;
}