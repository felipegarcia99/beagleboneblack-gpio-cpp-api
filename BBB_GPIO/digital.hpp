#include <iostream>

#define INPUT "in"
#define OUTPUT "out"

using namespace std;

void pinMode(int pin, string mode);
void export_gpio(int pin);
void direction_definer(int pin, string mode);
void digitalWrite(int pin, int state);
//void digitalRead(int pin); //soon...
void unexport_gpio(int pin);