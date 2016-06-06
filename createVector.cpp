#include <vector>
#include <iostream>

int main(){
	char arr[5] = {1,2,3,4,0,255};
	std::vector<double> v(arr,arr+5);
	for(auto& e : v){
		std::cout << e << ',';
	}
	std::cout << std::endl;
	return 0;
}
