#include <iostream>

#include "../include/my_vector.h"
#include "../include/inertial_driver.h"

int main(){
    lettura l1; 
    l1.yaw_v = 12.3; 

    std::cout << l1.yaw_v <<std::endl; 
    return 0;
}