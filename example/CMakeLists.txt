cmake_minimum_required(VERSION 3.10)
project(example_beagleboneblack_gpio)
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_BUILD_TYPE Debug)

#include_directories(../BBB_GPIO)
#link_directories(/usr/lib/mysqlcppconn8_ARM)

#set(PROJECT_LINK_LIBS libmysqlcppconn8.so)
add_executable(example main.cpp ../BBB_GPIO/digital.cpp ../BBB_GPIO/utils.cpp)
#target_link_libraries(sensorDataMySQL ${PROJECT_LINK_LIBS})
SET(CMAKE_CXX_FLAGS  "-pthread")

SET(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)