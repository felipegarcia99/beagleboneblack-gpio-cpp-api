#include <signal.h> //  our new library 

extern volatile sig_atomic_t flag;

void delay(float time);
void defining_sigaction();
void my_handler(int signal);