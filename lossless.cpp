#include <iostream>
#include <string>

std::string losslessDataCompression(std::string inputString, int width) {
    std::string ret;
    int l = inputString.size();
    for(int i=0;i<l;){
        std::string window;
        if( i > width){
            window = inputString.substr(i-width,width);
        }else{
            window = inputString.substr(0,i);
        }
        
        int w = 1;
        std::size_t pos;
        while(1){
			auto p = window.find(inputString.substr(i,w).c_str(),0,w);
            if(p == std::string::npos){
				--w;
				break;
			}
			pos = p;
            ++w;
        }
        if(w == 0){
			w = 1;
            ret = ret + inputString[i];
		}else{
            char buf[128];
            sprintf(buf,"(%d,%d)",int(pos),w);
            ret += buf;
        }
		i += w;
    }
    return ret;
}

int main(int, char* argv[]){
	std::cout << losslessDataCompression(std::string(argv[1]), std::atoi(argv[2]))<< std::endl;
}
