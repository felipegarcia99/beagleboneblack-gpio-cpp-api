#include "analog.hpp"
#include <sstream>
#include <fstream>

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

using namespace std;

int analogRead(int number){
   stringstream ss;
   ss << ADC_PATH << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> number;
   fs.close();
   return number;
}