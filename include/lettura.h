/**********
 * rappresenta una lettura delle 6 misurazioni (3 direzioni, velocità e accelerazione per ogni misura)
**********/

#ifndef lettura_h
#define lettura_h

struct Lettura{
    // yaw
    double yaw_v; //velocity
    double yaw_a; //acceleration

    // pitch
    double pitch_v; 
    double pitch_a; 

    // roll
    double roll_v; 
    double roll_a; 
     
};

#endif //lettura_h