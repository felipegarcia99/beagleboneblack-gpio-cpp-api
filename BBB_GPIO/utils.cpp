#include "utils.hpp"
#include <unistd.h>
#include <signal.h> //  our new library 

volatile sig_atomic_t flag = 0;

void delay(float time){
	usleep(time * 1000000);
}

void my_handler(int signal){ // can be called asynchronously
    flag = 1; // set flag
}

void defining_sigaction(){
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);
}