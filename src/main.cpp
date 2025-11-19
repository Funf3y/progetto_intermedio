#include <iostream>
#include "../include/MyVector.h"
#include "../include/InertialDriver.h"

int main(){
    lettura l1; 
    l1.yaw_v = 12.3; 

    std::cout << l1.yaw_v <<std::endl; 
    return 0;
}