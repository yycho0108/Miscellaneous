#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#define cnt1(x) __builtin_popcountll(x)

//for char 
#define clz(x) (__builtin_clz(x) - 8*(sizeof(int)-1))
#define ctz(x) __builtin_ctz(x)

#define MSB (9223372036854775808ULL)
//#define at(x,i,j) ((x >> (i*8+j)) & MSB)

#define namedPrint(x) \
	std::cout << #x << " : " << x << std::endl;
#define namedFprint(fout,x) \
	fout << #x << " : " << x << std::endl;



int N,K;

struct Boundary{
	int bi, bj, ei, ej;
};

union Grid {
	unsigned long long all;
	unsigned char rows[8];//in reverse order

	Grid(unsigned long long all=0):all(all){}

	unsigned char& row(int n){
		return rows[7-n];
	}

	void up(int n){
		all <<= 8*n;
	}

	void down(int n){
		all >>= 8*n;
	}

	void left(int n){
		for(int i=0;i<8;++i){
			rows[i] = rows[i]<<n;
		}
	}
	void right(int n){
		for(int i=0;i<8;++i){
			rows[i] = rows[i]>>n;
		}
	}
	void boundary(Boundary& b){
		int& bi = b.bi;
		int& bj = b.bj;
		int& ei = b.ei;
		int& ej = b.ej;

		bj = 8;
		ej = -1;
		for(int i=0;i<8;++i){
			bj = std::min(bj,(int)clz(row(i)));
			ej = std::max(ej,(int)(8-ctz(row(i))));
		}

		for(bi=0;row(bi)==0;++bi){
		//	namedPrint((int)row(bi));
		}
		//
		for(ei=7;row(ei)==0;--ei){
		//	namedPrint((int)row(ei));
		}
		++ei; //non-inclusive end
	}
};

using namespace std;
struct Piece{
	static unsigned long long board;
	static int board1s; //ones in board
	static void setBoard(vector<string>& p){
		board = Piece(p).piece;
		board1s = cnt1(board);
	}

	unsigned long long piece;
	Grid piece_g;
	Boundary b;

	Piece(vector<string>& p){ //convert to ull
		piece = 0;
		p.resize(8,std::string(8,'.'));
		for(auto& s : p){
			s.resize(8,'.');
			for(auto& c : s){
				piece <<= 1;
				if (c == '#'){
					piece |= 1;
				}
			}
		}
		piece_g.all = piece;
		normalize();
	}

	Piece(unsigned long long p):piece(p){
		piece_g.all = piece;
		normalize();
	}

	bool hashadd(Piece& o){
		auto a = cnt1(o.piece) + cnt1(piece);
		return (a == board1s && a == cnt1(o.piece | piece));
	}
	bool add(Piece& o){
		return (piece | o.piece) ==  board;
	}
	bool addPermute(Piece& o){
		auto leeway_i = N-b.ei; //leeway not to reach boundary
		auto leeway_j = N-b.ej;
		auto o_leeway_i = N-o.b.ei;
		auto o_leeway_j = N-o.b.ej;
		//namedPrint(leeway_i);
		//namedPrint(leeway_j);
		//namedPrint(o_leeway_i);
		//namedPrint(o_leeway_j);
		

		auto bk = piece;
		auto o_bk = o.piece;

		for(int i=0;i<=leeway_i;++i){
			down(i);
			for(int j=0;j<=leeway_j;++j){
				right(j);
				for(int p_i=0;p_i<=o_leeway_i;++p_i){
					o.down(p_i);
					for(int p_j=0;p_j<=o_leeway_j;++p_j){
						o.right(p_j);
						
						if(add(o))
							return true;
						o.piece_g = o.piece = o_bk;
					}
				}
				piece_g = piece = bk;
			}
		}
		return false;
	}
	void up(int n){
		piece_g.up(n);
		piece = piece_g.all;
	}
	void left(int n){
		piece_g.left(n);
		piece = piece_g.all;
	}
	void down(int n){
		piece_g.down(n);
		piece = piece_g.all;
	}
	void right(int n){
		piece_g.right(n);
		piece = piece_g.all;
	}

	void print(std::ostream& os){
		auto p = piece;
		for(int i=0;i<8;++i){
			for(int j=0;j<8;++j){
				os << ((p & MSB)?'#':'.');
				p <<= 1;
			}
			os << endl;
		}
		os << endl;
	}
	void normalize(){
		piece_g.boundary(b);

		up(b.bi);
		left(b.bj);

		b.ei -= b.bi;
		b.ej -= b.bj;

		b.bi = 0;
		b.bj = 0;
		//namedPrint(b.ei);
		//namedPrint(b.ej);
		//can go down for 8 - b.ei
		//can go right for 8 - b.ej
	}
};


std::ostream& operator<<(std::ostream& os, Piece& p){
	p.print(os);
	return os;
}
unsigned long long Piece::board = 0;
int Piece::board1s = 0;

int main(){

	std::ifstream f_in("bcs.in");
	std::ofstream f_out("bcs.out");
//	vector<string> v({
//			".###....",
//			"#..#..##",
//			"..##..##",
//			"####....",
//			"..####..",
//			".#.#.#.#",
//			"#.##.##.",
//			".....##."});

//	vector<string> v({
//			"........",
//			".#..##..",
//			"....##..",
//			"...##...",
//			"........",
//			"......#.",
//			"........",
//			"........",
//			});

	f_in >> N >> K;
	std::string s;
	std::getline(f_in,s);
	std::vector<Piece> ps;
	ps.reserve(K);

	for(int i=0;i<K+1;++i){
		std::vector<std::string> v;
		v.reserve(N);
		for(int j=0;j<N;++j){
			std::getline(f_in, s);
			v.push_back(s);
		}
		Piece p(v);
		ps.push_back(p);
	}

	Piece::board = ps.front().piece;
	Piece::board1s = cnt1(Piece::board);
	ps.erase(ps.begin());

	for(int i=0;i<K;++i){
		for(int j=i+1;j<K;++j){

			if(ps[i].addPermute(ps[j])){
				f_out << (i+1) << ' ' << (j+1);
				j=K;
				i=K;//break
			}
		}
	}
	//Piece p2(MSB);

	//p.add(p2);


	f_in.close();
	f_out.flush();
	f_out.close();
	return 0;
}
