#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>

const double PI = 3.1415926535;

class Matrix{
	friend Matrix dot(Matrix& a,Matrix& b);
	private:
		std::vector<std::vector<double>> m;
		int r,c;
	public:
		Matrix(int r, int c, const double* arr=nullptr):r(r),c(c){
			for(int i=0;i<r;++i){
				m.push_back(std::vector<double>(c));
			}
			if(arr){
				for(int i=0;i<r;++i){
					for(int j=0;j<c;++j){
						m[i][j] = arr[i*r+j];
					}
				}
			}
		}
		std::vector<double>& operator[](int i){
			return m[i];
		}
		void print(){
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					std::cout << m[i][j] << ' ';
				}
				std::cout << std::endl;
			}
		}
};

Matrix dot(Matrix& a, Matrix& b){
	Matrix res(a.r,b.c);
	assert(a.c == b.r);
	int len = a.c;
	for(int i=0;i<a.r;++i){
		for(int j=0;j<b.c;++j){
			double tmp = 0;

			for(int k=0;k<len;++k){
				tmp += a[i][k] * b[k][j];
			}

			res[i][j] = tmp;
		}
	}
	return res;
}


double d2r(double d){
	return d*PI/180;
}
double r2d(double r){
	return r*180/PI;
}
int main(){
	/*const double mat_1[] = {1.0,1.0,1.0,1.0};
	const double mat_2[] = {2.0,0.0,0.0,2.0};

	Matrix m_1(2,2,(const double*)mat_1);
	Matrix m_2(2,2,(const double*)mat_2);
	auto m_3 = dot(m_1,m_2);
	m_3.print();
	*/
	const double theta = d2r(90);
	const double R[] = {cos(theta),-sin(theta),sin(theta),cos(theta)};
	const double v[] = {1.0,0.0};
	Matrix m_1(2,2,(const double*)R);
	Matrix m_2(2,1,(const double*)v);
	auto m_3 = dot(m_1,m_2);
	m_3.print();

	return 0;
}
