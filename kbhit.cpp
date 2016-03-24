#include <linux/input.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

static const char *const evval[3] = {
    "RELEASED",
    "PRESSED ",
    "REPEATED"
};

int main(){
	auto input = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd",O_RDONLY); //read keyboard
	if(input == -1){
		fprintf(stderr,"Cannot open device: %s.\n", strerror(errno));
		return EXIT_FAILURE;
	}
	input_event ev;
	ssize_t n;
	while(1){
		n = read(input, &ev, sizeof(ev));
		if(n == (ssize_t)-1){
			if(errno == EINTR){
				continue;
			}else{
				break;
			}
		}else{
			if(n != sizeof(ev)){
				errno = EIO;
				break;
			}
		}

		if(ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2){
			printf("%s 0x%04x (%d)\n", evval[ev.value], (int)ev.code, (int)ev.code);
		}
	}
	fflush(stdout);
	fprintf(stderr, "%s.\n", strerror(errno));
	return EXIT_FAILURE;
}

