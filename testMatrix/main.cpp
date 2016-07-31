#include <vector>
#include <iostream>
#include "Matrix.h"

void f(std::vector<Matrix> w){
	for(auto& e : w){
		e.print(std::cout);
	}
}
int main(){
	std::vector<Matrix> v;
	for(int i=0;i<1;++i){
		v.push_back(Matrix::rand(3,3));
	}
	f(v);

	std::vector<Matrix> w = v;
	w[0] += 1;
	std::cout << "??" << std::endl;;
	f(w);
	std::cout << "??" << std::endl;;

	f(v);

	return 0;
}
