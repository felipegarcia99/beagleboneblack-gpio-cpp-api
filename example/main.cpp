#include <iostream>
#include "../BBB_GPIO/digital.hpp"
#include "../BBB_GPIO/utils.hpp"
#include <thread>

using namespace std;

void main_loop(int led1, int led2);
void sigint_handler(int led1, int led2);


int main(){
    int led1 = 50;
    int led2 = 51;

    thread t1(main_loop, led1, led2);
    thread t2(sigint_handler, led1, led2);

    t1.join();
    t2.join();

    return 0;
}

void main_loop(int led1, int led2){
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);

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

void sigint_handler(int led1, int led2){
   defining_sigaction();

    while (1)
    {
        if (flag){ // my action when signal set it 1
            printf("\n Signal caught!\n");
            unexport_gpio(led1);
            unexport_gpio(led2);
            exit(1);
       }
    }
}