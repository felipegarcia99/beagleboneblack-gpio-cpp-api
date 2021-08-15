#include "digital.hpp"
#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>

using namespace std;

void pinMode(int pin, bool mode){
    export_gpio(pin);
    direction_definer(pin, mode);
}

void export_gpio(int pin){
    //fstream fs;
	string pin_str = to_string(pin);

	cout << "Exporting GPIO" + pin_str << endl;
    //TESTE
    //fs.open("/sys/class/gpio/export");
    //fs << "50";

	system(("cd /sys/class/gpio && echo " + pin_str + " > export").c_str());
}

void direction_definer(int pin, bool mode){
    fstream fs;
	string pin_str = to_string(pin);

	cout << "Declaring direction " << mode << ", pin " << pin_str << endl;
	fs.open("/sys/class/gpio/gpio" + pin_str + "/direction");
	
    if (fs.fail()) {
        cerr << "Failure in setting direction. Error: " << strerror(errno) << '\n';
    } else {
        cerr << "Success in setting the direction\n";
        if (mode == true){fs << "out";} else {fs << "in";}
		fs.close();
    }
}

void digitalWrite(int pin, int state){
    fstream fs;
	string pin_str = to_string(pin);
	fs.open("/sys/class/gpio/gpio" + pin_str + "/value");
	fs << to_string(state);
	fs.close();
}

void unexport_gpio(int pin){
    //fstream fs;
	string pin_str = to_string(pin);

	cout << "Unexporting GPIO" + pin_str << endl;

	system(("cd /sys/class/gpio && echo " + pin_str + " > unexport").c_str());
}