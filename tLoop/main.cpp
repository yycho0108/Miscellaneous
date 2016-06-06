#include <stdio.h>
template <int N>
void print(){
	print<N-1>();
	printf("%d\n", N);
	//std::cout << N << std::endl;
}

template<>
void print<0>(){
	printf("INITIALIZED:::\n");
}


int main(){
	print<100>();
}
