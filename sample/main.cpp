#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <random>

class Sampler{

private:
	using rng_type = std::mt19937;
	rng_type rng;

public:
	Sampler(){
	  rng_type::result_type const seedval = time(0); // get this from somewhere
	  rng.seed(seedval);
	}

	std::vector<int> operator()(int range, int nSamples){
		std::vector<int> res;
		std::uniform_int_distribution<rng_type::result_type> udist(0,range);

		for(int i = 0; i < nSamples; ++i)
		{
		   int r;
		   do{
			  r = udist(rng);
		   }while(std::find(res.begin(), res.end(), r) != res.end());
		   res.push_back(r);
		}

		return res;
	}

};

template <typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T> v){
	for(auto& e : v){
		o << e << ',';
	}
	return o;
}

std::vector<int> sample(int range, int nSamples){
	std::vector<int> res;

	for(int i = 0; i < nSamples; ++i)
	{
	   int r;
	   do{
	      r = rand()%range;
	   }while(std::find(res.begin(), res.end(), r) != res.end());
	   res.push_back(r);
	}

	return res;
}

int main(){
	srand(time(0));
	Sampler sampler;
	int test[60000] = {};
	for(int i=0; i<10000; ++i){
		auto v = sampler(60000,128);
		for(auto& e : v){
			++test[e];
		}
		//std::cout << v << std::endl;
	}

	for(int i=0;i<60000;++i){
		std::cout << test[i] << ' ';
	}
}
