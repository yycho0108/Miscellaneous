#include <vector>
#include <bitset>
#include <iostream>
#include <map>
#include <list>
#include <ctime>

int memoize[1000000];
std::map<int,int> memoize_2;

int maxLen = 0;
int maxVal = 0;

int memory(long long int i){
	if(0<=i && i < 1000000){
		return memoize[i];
	}else{
		return memoize_2[i];
	}

}
void memorize(long long int i, int len){
	if(0<=i && i < 1000000){
		memoize[i] = len;
	}else{
		memoize_2[i] = len;
	}

}
int main(){
	auto start = std::clock();
	memorize(1,1);
	for(int i=1;i<1000000;++i){
		long long int ti = i;
		std::list<long long int> route;
		while(!memory(ti)){
			route.push_front(ti);
			ti = ti&1?(3*ti+1):(ti/2);
		}
		auto l = memory(ti);
		for(auto n : route){
			memorize(n,++l);
		}
		if(maxLen < l){
			maxLen = l;
			maxVal = i;
		}
		maxLen = maxLen>l?maxLen:l;
	}
	std::cout << maxVal;
	std::cout << "Took : " << double(std::clock() - start)/CLOCKS_PER_SEC << "seconds\n";
}
