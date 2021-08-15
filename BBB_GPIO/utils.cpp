#include "utils.hpp"
#include <unistd.h>

void delay(float time){
	usleep(time * 1000000);
}