#include <iostream>

#define clz(x) (__builtin_clz(x) - 8*(sizeof(int)-1))
#define ctz(x) __builtin_ctz(x)

using namespace std;

int main(){
	unsigned char c = 5;
	cout << clz(c) << ',' << ctz(c) << endl;	
}
