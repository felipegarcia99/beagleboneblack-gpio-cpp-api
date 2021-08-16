#include "digital.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <cstring>

#define GPIO_PATH "/sys/class/gpio"

using namespace std;

void pinMode(int pin, string mode){
    export_gpio(pin);
    direction_definer(pin, mode);
}

void export_gpio(int pin){
    fstream fs;
	string pin_str = to_string(pin);

	cout << "Exporting GPIO" + pin_str << endl;
    //TEST: DON'T WORK
    //fs.open("/sys/class/gpio/export");
    //fs << "50";

    //TEST2
    /*stringstream ss;
    ss << GPIO_PATH << "/export";
    fs.open(ss.str().c_str());
    fs << pin_str;*/

    system(("cd " + string(GPIO_PATH) + " && echo " + pin_str + " > export").c_str());
}

void direction_definer(int pin, string mode){
    fstream fs;
	string pin_str = to_string(pin);

	cout << "Declaring direction " << mode << ", pin " << pin_str << endl;

    stringstream ss;
    ss << GPIO_PATH << "/gpio"<< pin_str << "/direction";
    fs.open(ss.str().c_str());
	
    if (fs.fail()) {
        cerr << "Failure in setting direction. Error: " << strerror(errno) << '\n';
    } else {
        cerr << "Success in setting the direction\n";
        fs << mode;
		fs.close();
    }
}

void digitalWrite(int pin, int state){
    fstream fs;
	string pin_str = to_string(pin);

    stringstream ss;
    ss << GPIO_PATH << "/gpio"<< pin_str << "/value";
    fs.open(ss.str().c_str());

	fs << to_string(state);
	fs.close();
}

void unexport_gpio(int pin){
	string pin_str = to_string(pin);
	cout << "Unexporting GPIO" + pin_str << endl;
	system(("cd " + string(GPIO_PATH) + " && echo " + pin_str + " > unexport").c_str());
}