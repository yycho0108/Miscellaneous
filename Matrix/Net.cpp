#include "Matrix.h"

Matrix sigmoid(Matrix m){
	m.forEach([](double a){return 1.0 / (1.0 + exp(-a));});
	return m;
}
Matrix sigmoidPrime(Matrix m){
	m.forEach([](double a){
			auto s = 1.0/(1.0 + exp(-a));
			return s*(1.0-s);
			});
	return m;
}
class Layer{
	friend class Net;
	private:
		int l;
		Matrix I,O,G;
	public:
		Layer(int l):l(l){}
};

class Net{
	private:
		std::vector<Layer> L;
		std::vector<Matrix> W;
	public:
		Net(std::vector<int> topology);
		Matrix FF(Matrix& X);
		Matrix BP(Matrix& X, Matrix& Y);
};


Net::Net(std::vector<int> T){
	for(size_t i=0; i<T.size(); ++i){
		L.push_back(Layer(T[i]));
	}
	for(size_t i=1;i<T.size(); ++i){
		W.push_back(Matrix(T[i],T[i-1]));
	}

}

Matrix Net::FF(Matrix& X){
	L[0].O = X;
	for(size_t i=1; i<L.size(); ++i){
		L[i].I = dot(W[i-1],L[i-1].O);
		L[i].O = sigmoid(L[i].I);
	}
	return L.back().O;
}

Matrix Net::BP(Matrix& X, Matrix& T){
	auto Y = FF(X);
	auto G = T - Y;
	L.back().G = G * sigmoidPrime(L.back().O);
	for(int i = L.size()-1; i>=1; --i){
		L[i].G = dot(L[i+1].G,W[i].transpose()) * sigmoidPrime(L[i].I);
	}
}
