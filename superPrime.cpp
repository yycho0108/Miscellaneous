#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

int n; // end-length
std::vector<int> cache({2,3,5,7,11});

bool isPrime(int n){ //very inefficient
	if(n<=1 || (n!=2 && n%2==0))
		return false;
	double sqrtn = sqrt(n);
	for(int i=3;i<=sqrtn;i+=2){
		if(n%i ==0) //nonprime
			return false;
	}
	return true;
}
void getNextPrime(){
	int i = cache.back()+1;
	while(1){
		for(auto j : cache){
			if(i%j == 0){
				i+=2;
				break;
			}
		}
	}

}
bool isEfficientPrime(int n){
	// incomplete
	if(cache.back() < n){
		double sqrtn = sqrt(n);
		for(int i = cache.back()+1; i <= sqrtn; i+=2){
			if(auto j : cache){
				if(i%j == 0) // = nonprime
					break;
			}
		}
	}
	return std::binary_search(cache.begin(),cache.end(),n);
}
void Ribify(int num, int dig){
	if(dig >=n){
		std::cout << num << std::endl;
		return;
	}
	else{
		for(int i=0;i<10;++i){
			auto next = num*10+i;
			if(isPrime(next))
				Ribify(next,dig+1);
		}
	}

}

int main(int argc, char* argv[]){
	n = 4; // default value
	if(argc > 1)
		n = std::atoi(argv[1]);
	// end-length set.
	Ribify(0,0);
}
