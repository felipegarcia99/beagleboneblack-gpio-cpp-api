cmake_minimum_required(VERSION 3.10)
project(example_beagleboneblack_gpio)
set(CMAKE_CXX_STANDARD 11)

add_executable(example main.cpp ../BBB_GPIO/digital.cpp ../BBB_GPIO/utils.cpp)
SET(CMAKE_CXX_FLAGS  "-pthread")

SET(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)