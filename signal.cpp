#include <signal.h>
#include <iostream>

static volatile int keepRunning = 1;

void intHandler(int){
	keepRunning = 0;
}

int main(void){
	signal(SIGINT, intHandler);
	int i=0;
	while(keepRunning){
		std::cout << "RUNNING...(" << ++i << std::endl;		
	}
	std::cout << "COMPLETE!" << std::endl;
}
