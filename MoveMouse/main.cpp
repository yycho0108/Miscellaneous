#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <linux/input.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <pthread.h>


enum DIR: char {X=-1,U,L,R,D};//X is considered out-of-bounds
enum : char {RELEASED, PRESSED, REPEATED};

class Controller{
private:
	int kb,ms; // --> keyboard identifier
	input_event kb_ev;
	input_event ms_ev, ms_ev_end;
	DIR dir;

public:
	Controller(const char* kbDev, const char* msDev){
		kb = open(kbDev,O_RDONLY);
		if(kb == -1){
			fprintf(stderr,"Cannot open device %s: %s.\n", kbDev,strerror(errno));
			close(kb);
			throw("CANNOT OPEN DEVICE");
		}

		ms = open(msDev, O_RDWR);
		if (ms < 0) {
			printf("Errro open mouse:%s\n", strerror(errno));
			close(ms);
			throw("CANNOT OPEN DEVICE");
		}

		dir = X;
	}

	~Controller(){
		close(kb);
		close(ms);
	}

	bool kbread(){
		dir = X;

		ssize_t bytes = read(kb,&kb_ev,sizeof(kb_ev));
		
		if(bytes == (ssize_t)-1){
			if(errno == EINTR){
				return true;
			}
			else{
				return false;
			}
		}else if(bytes != sizeof(kb_ev)){
			errno = EIO;
			return false;
		}


		if(kb_ev.type == EV_KEY){
			switch(kb_ev.value){
				case REPEATED:
				case PRESSED:
					switch(kb_ev.code){
						case 0x0067: //UP
							dir = U;
							break;
						case 0x0069: //LEFT
							dir = L;
							break;
						case 0x006a: //RIGHT
							dir = R;
							break;
						case 0x006c: //DOWN
							dir = D;
							break;
						default:
							break;
					}
					break;
				case RELEASED:
					dir = X;
					break;
			}
		}
		return true;
	}

	void mswrite(){
		memset(&ms_ev, 0, sizeof(ms_ev));
		memset(&ms_ev_end, 0, sizeof(ms_ev_end));
		gettimeofday(&ms_ev.time, NULL);
		ms_ev.type = EV_REL;
		switch(dir){
			case U:
				ms_ev.code = REL_Y;
				ms_ev.value = -10;
				break;
			case L:
				ms_ev.code = REL_X;
				ms_ev.value = -10;
				break;
			case R:
				ms_ev.code = REL_X;
				ms_ev.value = 10;
				break;
			case D:
				ms_ev.code = REL_Y;
				ms_ev.value = 10;
				break;
			case X:
			default:
				//do nothing
				return;
		}
  		gettimeofday(&ms_ev_end.time, NULL);
  		ms_ev_end.type = EV_SYN;
  		ms_ev_end.code = SYN_REPORT;
  		ms_ev_end.value = 0;

		write(ms, &ms_ev, sizeof(ms_ev));// Move the mouse
		write(ms, &ms_ev_end, sizeof(ms_ev_end));// Show mov
	}


	void run(){
		while(kbread()){
			mswrite();
		}
	}
	
};


int main() {
	Controller controller("/dev/input/by-path/platform-i8042-serio-0-event-kbd","/dev/input/event7");
	controller.run();
	return 0;
}
