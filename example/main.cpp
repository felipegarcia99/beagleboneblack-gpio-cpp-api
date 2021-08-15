#include <iostream>
#include "../BBB_GPIO/digital.hpp"
#include "../BBB_GPIO/utils.hpp"
#include <signal.h> //  our new library 
#include <thread>

using namespace std;

void defining_sigaction();
void my_handler(int signal);
void main_loop();
void sigint_handler();

volatile sig_atomic_t flag = 0;
int led1 = 50;
int led2 = 51;

int main(){
    thread t1(main_loop);
    thread t2(sigint_handler);

    t1.join();
    t2.join();

    return 0;
}

void main_loop(){
    pinMode(led1, true);
    pinMode(led2, true);

    while (1)
    {
        digitalWrite(led1, 1);
        delay(1);
        digitalWrite(led1, 0);
        digitalWrite(led2, 1);
        delay(1);
        digitalWrite(led2, 0);
    }
}

void sigint_handler(){
   defining_sigaction();

    while (1)
    {
        if (flag){ // my action when signal set it 1
            printf("\n Signal caught!\n");
            //printf("\n default action it not termination!\n");
            //flag = 0;
            unexport_gpio(led1);
            unexport_gpio(led2);
            exit(1);
       }
    }
    

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