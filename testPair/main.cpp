#include <utility>
#include <iostream>

int main(){
	int a = 1;
	int b = 2;
	auto c = std::make_pair(a,b);

	c.first = 3;
	c.second = 4;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
}
