#include <iostream>
#include <fstream>

template<int n>
int tester(){
	return n;
}

constexpr int hyperParam(const char* s){
	return 1;
}

int main(){
	std::cout << tester<hyperParam("")>() << std::endl;
}
