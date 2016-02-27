#include <vector>
#include <iostream>

const int _month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
const char* d[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
bool leap(int y){
    if((y%4)==0 && (y%100) != 0)
        return true;
    if((y%400)==0)
        return true;
    return false;
}
int month(int m, int y){
    if(m == 2){
        return leap(y)?29:28;
    }else{
        return _month[m];
    }
}
std::vector<int> parse(std::string& date){
    int d,m,y;
    sscanf(date.c_str(),"%02d/%02d/%04d",&d,&m,&y);
    return std::vector<int>({d,m,y});
}
std::string getNext(std::string& date, int n){
    auto v = parse(date);
    int d = v[0],m = v[1],y = v[2];
    d += n;
    while(d > month(m,y)){
        d -= month(m,y);
        ++m;
        while(m > 12){
          ++y;
		  m=0; 
        }
    }
    char* o = "dd/mm/yyyy";
    sprintf(o,"%02d/%02d/%04d",d,m,y);
    return std::string(o);
}
std::vector<std::string> recurringTask(std::string firstDate, int k, std::vector<std::string> daysOfTheWeek, int n) {
    
    char* o = "dd/mm/yyyy";
}
