cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
project(InertialDriver)

include_directories(include)

add_library(${PROJECT_NAME} SHARED src/inertial_driver.cpp src/misura.cpp)

add_library(myvector SHARED src/my_vector.cpp)

add_executable(main src/main.cpp)

target_link_libraries(${PROJECT_NAME} myvector)

target_link_libraries(main ${PROJECT_NAME})

