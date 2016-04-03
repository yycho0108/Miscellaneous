#include <vector>
#include <iostream>
// Pointer To Vector
// 
int main(){
	char stuff[10] = {0,1,2,3,4,5,6,7,8,9};
	std::vector<double> v(stuff, stuff+10);
	for(auto& e : v){
		std::cout << e << ", ";
	}
	std::cout << std::endl;
}
