#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
	int cumTotal[10000] = {}; //cumulative total
	std::ifstream f_in("diamond.in");
	std::ofstream f_out("diamond.out");

	int N,K;
	f_in >> N >> K;
	int* D = new int[N];

	for(int i=0;i<N;++i){
		f_in >> D[i];
	}
	std::sort(D,D+N);


	int curNum = 0;
	for(int i=0;i<N;++i){
		auto e = D[i];
		if(e != curNum){
			for(int j=curNum;j<e;++j){
				cumTotal[j] = i;
			}
			//cumTotal[curNum] = i; //# of diamonds smaller than this
			curNum = e;
		}
	}
	cumTotal[curNum] = N;

	for(int i=0;i<=curNum;++i){
		cout << cumTotal[i] << ' ';
	}


	int maxVal = 0;
	for(int i=K+1;i<N;++i){
		auto val = cumTotal[i] - cumTotal[i-K-1];
		maxVal = val>maxVal?val:maxVal;
	}


	f_out << maxVal;
	f_out.flush();


	f_in.close();
	f_out.close();

	delete[] D;

	return 0;
}
