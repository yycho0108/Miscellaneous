#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;
std::map<int,string> cache;
string flip(string s){
	for(auto& c : s){
		c = c=='O'?'X':'O';
	}
	return s;
}
string OXXO(int n){
	if(n <= 0)
		return "O";
	else{
		auto i = cache.find(n);
		if(i != cache.end())
			return i->second;
		auto s = OXXO(n-1);
		return cache[n] = s + flip(s);
	}
}

int main(int argc, char* argv[]){
	int n = 0;
	if(argc>1)
		n = std::atoi(argv[1]);
	std::cout << OXXO(n);
	return 0;
}
