#ifndef lettura_h
#define lettura_h

/*STRUCT LETTURA*/
//Rappresentazione dei sei valori acquisiti da un sensore
struct Lettura{
    // yaw
    double yaw_v; //velocity
    double yaw_a; //acceleration

    // pitch
    double pitch_v; //velocity
    double pitch_a; //acceleration


    // roll
    double roll_v; //velocity
    double roll_a; //acceleration

     
};

#endif //lettura_h