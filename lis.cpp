#include <vector>
#include <iostream>

std::vector<int> getLIS(std::vector<int>& s){
	std::vector<std::vector<int>> cache; //min subsequences.
	cache.push_back(std::vector<int>({0})); // "subsequence of length 0"
	for(auto k : s){ //from beginning to end
		int l = cache.size();
		for(int i = 0; i < l; ++i){ // i = length of subsequence
			if(cache[i].back() < k){
			   if(i == l-1){ //longest
				   cache.push_back(cache.back());
				   cache.back().push_back(k);
			   }else if (cache[i+1].back() > k){
				   cache[i+1] = cache[i]; //copy
				   cache[i+1].push_back(k);
			   }
		   }

		}
	}
	return cache.back();
}

int main(int argc, char* argv[]){
	auto s = std::vector<int>({9,1,5,3,6,8,2,7,13});
	if(argc > 1){
		s.clear();
		for(int i=1; i<argc; ++i){
			s.push_back(atoi(argv[i]));
		}
	}
	auto ss = getLIS(s);
	ss.erase(ss.begin());
	for(auto i : ss){
		std::cout << i << ' ';
	}
	return 0;
}
