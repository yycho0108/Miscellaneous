#include "Matrix.h"

//static func
Matrix::Matrix(int r, int c, double* arr)
	:r(r),c(c){
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

Matrix::Matrix(int r, int c, double val)
	:r(r),c(c){
	for(int i=0;i<r;++i){
		m.push_back(std::vector<double>(c,val));
	}	
}


//Element-wise
Matrix& Matrix::operator+=(Matrix& o){
	assert(r ==o.r && c==o.c);
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			m[i][j] += o.m[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(Matrix& o){
	assert(r ==o.r && c==o.c);
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			m[i][j] -= o.m[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(Matrix& o){
	assert(r ==o.r && c==o.c);
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			m[i][j] *= o.m[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator/=(Matrix& o){
	assert(r ==o.r && c==o.c);
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			m[i][j] /= o.m[i][j];
		}
	}
	return *this;
}

//with scalar
Matrix& Matrix::operator+=(double o){
	forEach([o](double e){return e+o;});
	return *this;
}
Matrix& Matrix::operator-=(double o){
	forEach([o](double e){return e-o;});
	return *this;
	//Matrix _o(r,c,o);
	//return (*this -= _o);
}
Matrix& Matrix::operator*=(double o){
	forEach([o](double e){return e*o;});
	return *this;
	//Matrix _o(r,c,o);
	//return (*this *= _o);
}
Matrix& Matrix::operator/=(double o){
	forEach([o](double e){return e/o;});
	return *this;
	//Matrix _o(r,c,o);
	//return (*this /= _o);
}

std::vector<double>& Matrix::operator[](int i){
	return m[i];
}

Matrix Matrix::dot(Matrix& o){
	Matrix res(r,o.c);
	assert(c == o.r);
	int len = c;
	for(int i=0;i<r;++i){
		for(int j=0;j<o.c;++j){
			double tmp = 0;
			for(int k=0;k<len;++k){
				tmp += m[i][k] * o.m[k][j];
			}
			res[i][j] = tmp;
		}
	}
	return res;
}
//matrix operation
Matrix Matrix::transpose(){
	Matrix t(c,r);
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			t.m[j][i] = m[i][j];
		}
	}
	return t;
}

Matrix dot(Matrix a, Matrix b){
	return a.dot(b);
}
Matrix& Matrix::forEach(std::function<double(double)> f){
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			m[i][j] = f(m[i][j]);
		}
	}
	return *this;
}
//element-wise
