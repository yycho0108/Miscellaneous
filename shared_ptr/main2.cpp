#include <memory>
#include <iostream>

int main(){
	std::shared_ptr<int> p(new int(15));
	std::cout << *p << std::endl;
	std::cout << "SIZE : " << sizeof(p) << std::endl;
}
