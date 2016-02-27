#include <string>
#include <vector>
#include <iostream>

int getTime(std::string info){
    int h,m;
    sscanf(info.c_str(),"%2d:%2d",&h,&m);
    return h*60+m;
}


struct order{
    int start,end;
    //bool served;
    order(std::string& info, int leadTime){
        start = getTime(info);
        end = start + leadTime;
        //served = false;
    }
};
struct shopper{
    int start,end;
    bool worked;
    shopper(std::vector<std::string>& info){
        start = getTime(info[0]);
        end = getTime(info[1]);
        worked = false;
    }
    bool cando(order& o){
        return (start <= o.start && o.end <= end);
    }
};
bool simulate(std::vector<shopper>& pool, std::vector<order>& orders, int numServed){
    if(orders.size() == numServed)
        return true;
    for(auto& w : pool){
        if(!w.worked && w.cando(orders[numServed])){
            w.worked = true;
            if(simulate(pool,orders,numServed+1) == true)
				return true;
            w.worked = false;
        }
    }
	return false;
}
bool busyHolidays(std::vector<std::vector<std::string>> shoppers, std::vector<std::vector<std::string>> orders, std::vector<int> leadTime) {
    std::vector<shopper> ss;
    std::vector<order> oo;
    for(auto& s : shoppers){
        ss.push_back(shopper(s));
    }
    for(int i=0;i<orders.size();++i){
        oo.push_back(order(orders[i],leadTime[i]))
    }
    return simulate(ss,oo,0);
}
