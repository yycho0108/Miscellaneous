#include <iostream>

template<typename T>
class shared_ptr{
	private:
		T* ptr;
		int* _count;
	public:
		shared_ptr(T*& ptr):ptr(ptr){
			//take ownership
			ptr = nullptr;
			//raise _counter
			_count = new int(1);
		}
		shared_ptr(T*&& ptr):ptr(ptr){
			//take ownership
			ptr = nullptr;
			//raise _counter
			_count = new int(1);
		}
		shared_ptr(const shared_ptr& o){
			ptr = o.ptr;
			_count = o._count;
			++(*_count);
		}
		shared_ptr& operator=(const shared_ptr& o){
			++(*o._count);
			--(*_count);
			if(*_count == 0){
				delete ptr;
				delete _count;
			}

			ptr = o.ptr;
			_count = o._count;

			return *this;
		}
// 		shared_ptr(shared_ptr&& o){
// 			ptr = o.ptr;
// 			_count = o._count;
// 			++(*_count);
// 		}
		~shared_ptr(){
			std::cout << " DESTRUCTION : " << count() << std::endl;
			--(*_count);
			if(*_count == 0){
				std::cout << "COUNT IS ZERO FOR VALUE " << *ptr << std::endl;
				delete ptr;
				delete _count;
			}
		}
		T& operator*(){
			return *ptr;
		}
		int count(){
			return *_count;
		}
};

void func(shared_ptr<int> p){
	std::cout << *p << std::endl;
	std::cout << "COUNT : " << p.count() << std::endl;
}

int main(){
	int* some_ptr = new int(14);
	shared_ptr<int> s_ptr(some_ptr);

	shared_ptr<int> ptr(new int(15));
	std::cout << *ptr << std::endl;
	func(ptr);
	func(ptr);
	auto p = ptr;
	func(ptr);
	p = shared_ptr<int>(new int(16));

	shared_ptr<int> ppt(shared_ptr<int>(new int(17)));
	func(ppt);
	std::cout << *ppt << std::endl;
}
