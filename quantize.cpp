#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

vector<int> seq;
vector<int> sumSeq;
vector<int> sqSumSeq;


int getErr(int beg, int end){
	// 2*n*(end - beg + 1)+ 2*(sumSeq[end] - sumSeq[beg]) = 0
	int n =  0.5 + double(sumSeq[end]-sumSeq[beg])/(end - beg); //avg.
	auto res = (sqSumSeq[end] - sqSumSeq[beg]) //30
		- 2*n*(sumSeq[end] - sumSeq[beg])
		+ (end-beg)*n*n;
	return res;
}
int quantize(int beg, int end, int n){
	if(n == 1) //one region left
		return getErr(beg,end);
	int min = INT16_MAX;
	for(auto i = beg+1; i < end; ++i){
		auto res = getErr(beg,i) + quantize(i,end,n-1);
		min = min<res?min:res;
	}

	return min;
}

int main(){
	int i;
	sumSeq.push_back(0);
	sqSumSeq.push_back(0);
	while(std::cin >> i){
		seq.push_back(i);
		sumSeq.push_back(sumSeq.back() + i);
		sqSumSeq.push_back(sqSumSeq.back() + i*i);
	}	
	cout << quantize(0,seq.size(),5); // 4 = # partition
	return 0;
}
