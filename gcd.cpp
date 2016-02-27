#include <iostream>
#include <vector>

using namespace std;

int _gcd(int a, int b){
    while ( b != 0) {
        auto r = a % b;
        a = b;
        b = r;
    }
    return a;
}
template<typename T> int gcd(T& a){
    return a;
}
template<typename First, typename... Rest> int gcd(First& a, Rest... b){
    return _gcd(a,gcd(b...));
}

struct g{
	template<typename... T>
	int operator()(T... a){
		std::cout << gcd(a...) << std::endl;
	}
};

template <size_t... Indices>
struct indices{
	using next = indices<Indices..., sizeof...(Indices)>;
};
template <std::size_t N>
struct build_indices{
	using type = typename build_indices<N-1>::type::next;
};
template <>
struct build_indices<0>{
	using type = indices<>;
};
template <std::size_t N>
using BuildIndices = typename build_indices<N>::type;

template<size_t num_args>
struct unpack_caller{
	private:
		template <typename FuncType, size_t... I>
		void call(FuncType& f, std::vector<int>& args, indices<I...>){
			f(args[I]...);
		}
	public:
		template<typename FuncType>
		void operator()(FuncType& f, std::vector<int>& args){
			call(f,args,BuildIndices<num_args>{});
		}

};

int main(int argc, char* argv[]){
	std::vector<int> v;
	for(int i=1;i<argc;++i){
		v.push_back(std::atoi(argv[i]));
	}
	
	//for(auto i : v){
	//	std::cout << i << ' ';
	//}
	//std::cout << std::endl;

	g G;
	unpack_caller<5>()(G,v);
}
