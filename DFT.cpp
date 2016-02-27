#include <vector>
#include <iostream>
//#include <cmath>
#include <complex>
#include <functional>

using complex = std::complex<double>;

// constants
auto PI = 3.14159265358979323846264338327950;
auto i = complex(0.0,1.0);

struct ContFunc{
	std::vector<complex> v;
	ContFunc(){
	}
	ContFunc(std::vector<complex>& v):v(v){
	}
	void setFunc(std::vector<complex> _v){
		v.swap(_v);
	}
	complex operator()(double t){
		//linear interpolation to create continuous value
		//
		auto w = t - std::floor(t);
		return (1-w)*v[t] + w*v[t+1];
	}
};

complex integrate(double beg, double end, int n, std::function<complex(double)> f){
	double step = (end-beg)/n;
	complex sum(0.0,0.0);
	for(int i=0;i<n;++i){
		sum += 1.0/n*f(beg + step * i);
	}
	return sum;
}

double sinc(double x){
	return x==0?1:sin(x)/x;
}

double mag(complex& c){
	return sqrt(c.imag()*c.imag() + c.real()*c.real());
}

double mag(double& c){
	return c;
}
template<typename T>
void print(std::vector<T> v){
	for(auto& e : v){
		std::cout << e << ',';
	}
}
/*
 *
#define CONTINUOUS
std::vector<double> DFT(std::vector<double> v){
	std::vector<double> c;
	//int div_size = 100; //arbitrary division_max
	double T = 100; //arbitrary period
	ContFunc f(v);
	for(size_t t=0;t<v.size();++t){
#ifdef CONTINUOUS
		auto int_f = [&](double it){return f(t)*exp(-2*PI/T*t*it*i);};
		auto val = 1/T*integrate(-T/2,T/2,100,int_f);	
		c.push_back(mag(val));
#elif defined ELIM
		double w = 2*PI*t/T; //angle
		complex val = (v[t] / T) * (-1.0/(i*w)) * (-2*PI*t*i) * (exp(-w*T/2*i) - exp(w*T/2*i));
		c.push_back(mag(val));
#else

#endif
		//double val = v[t]*sin(-2*PI*t*(T_1/T)); //T/2 = T_1

	}
	return c;
}
*/
struct DFT{
	std::vector<complex> v;
	std::vector<complex> c;
	ContFunc f_time;
	ContFunc f_freq;
	DFT(){}
	std::vector<complex> fw(){
		c.clear();
		auto size = v.size();
		for(double w = 0; w < 10; w+=0.01){ // w ~ .25, /6.28 = 0.04
			/*
			 * complex tmp(0,0);
			for(auto t=0;t<size;++t){
				//auto tt = t / 100.0; //real time, s
				auto val = v[t]*exp(-w*t*i);
				tmp += 1/double(size) * val;
			}
			*/
			auto val = integrate(0,size,10000,[&](double t){return f_time(t)*exp(-w*t*i);});//w in rad
			c.push_back(val);
		}
		f_freq = ContFunc(c);
		return c;
	}
	std::vector<complex> bk(){
		auto size = c.size();
		std::vector<complex> res;
		for(size_t t=0;t<size;++t){
			auto val = integrate(0,size,10000,[&](double w){return 1/(2*PI)*f_freq(w)*exp(w*t*i);});
			res.push_back(val);
		}
		return res;
	}
	void setFT(std::vector<double>& v){
		this->v.reserve(v.size());
		for(auto& c : v){
			this->v.push_back(complex(c,0.0));
		}
		f_time = ContFunc(this->v);
	}
	//void setFW(std::vector<double>& v){
	//	f_freq = ContFunc(v);
	//}
};

std::vector<double> toReal(std::vector<complex>& v){
	std::vector<double> res;
	res.reserve(v.size());
	for(auto& c : v){
		res.push_back(mag(c));
	}
	return res;
}
int main(int argc, char* argv[]){
	int freq = 7;
	if(argc>1)
		freq = std::atoi(argv[1]);

	std::vector<double> v;
	v.reserve(100);
	for(int i=0;i<100;++i){ //over 1 seconds
		auto angle = (i/100.0) * (freq);// freq = 7 Hz(rad/sec)
		v.push_back(std::cos(angle));
		//v.push_back(1.0);
		//sampling frequency = 100 Hz
		//
	}
	//composition
	freq = 30;
	for(int i=0;i<100;++i){
		auto angle = (i/100.0) * (freq);
		v[i] += 0.5 * std::sin(angle);
	}
	//print(v);
	auto DFTManager = DFT();
	DFTManager.setFT(v);
	auto c = DFTManager.fw();
	//c = DFTManager.bk();
	print(toReal(c));
	return 0;
}
