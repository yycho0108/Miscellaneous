#include <vector>
#include <algorithm>
#include <iostream>

int main(){
	std::vector<int> v(500);
	std::iota(v.begin(),v.end(),0);
	for(auto& e : v){
		std::cout << e << ' ';
	}
}
