#include <boost/bind.hpp>
#include <iostream>

template<typename T>
struct callback{
	std::string topic;
	callback(std::string topic):topic(topic){

	}

	void operator()(T msg){
		std::cout << topic << std::endl;
		std::cout << msg << std::endl;
		return;
	}
};

int main(){
	auto c = callback<int>("TOPIC");
	c(5);
}
