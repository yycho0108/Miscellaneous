#include <vector>
#include <cassert>
#include <cmath>
#include <iostream>
#include <functional>
class Matrix{
	private:
		int r,c;
		std::vector<std::vector<double>> m;
	public:
		//Initialiaztions
		Matrix();
		Matrix(int r,int c,double* arr=nullptr);
		Matrix(int r,int c,double val);

		//Operations
		Matrix& operator+=(Matrix&);
		Matrix& operator-=(Matrix&);
		Matrix& operator*=(Matrix&);
		Matrix& operator/=(Matrix&);

		Matrix& operator+=(double);
		Matrix& operator-=(double);
		Matrix& operator*=(double);
		Matrix& operator/=(double);

		Matrix operator+(Matrix);
		Matrix operator-(Matrix);
		Matrix operator*(Matrix);
		Matrix operator/(Matrix);

		Matrix operator+(double);
		Matrix operator-(double);
		Matrix operator*(double);
		Matrix operator/(double);

		std::vector<double>& operator[](int);

		Matrix dot(Matrix&);
		//Matrix cross(Matrix&);
		Matrix transpose();
		
		Matrix& forEach(std::function<double(double)>);
		//Utilities
		void print();
};

//matrix operation
Matrix dot(Matrix a, Matrix b);
//element-wise
Matrix add(Matrix& a, Matrix& b);
Matrix sub(Matrix& a, Matrix& b);
Matrix mul(Matrix& a, Matrix& b);
Matrix div(Matrix& a, Matrix& b);
