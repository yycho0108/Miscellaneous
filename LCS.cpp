std::vector<int> getLCS(std::string& a, std::string& b){
    if(a.size() > b.size()){
        auto t = _getLCS(b,a);
        auto tmp = t[2];
        t[2] = t[1];
        t[1] = tmp;
        return t;
    }else{
        return _getLCS(a,b);
    }
}
std::vector<int> _getLCS(std::string& a, std::string& b){
    int maxW = 0;
    int aBeg;
    int bBeg;
    int l = a.size();
    for(int i=0;i<l;++i){
        int w = 1;
        while(i+w<l && b.find(a.substr(i,w))!=std::string::npos){
            ++w;
        }
        --w;
        
        if(w > maxW){
            maxW = w;
            aBeg = i;
            bBeg = b.find(a.substr(i,w));
        }
        
    }
    return std::vector<int>({maxW,aBeg,bBeg});
}
std::string displayDiff(std::string oldVersion, std::string newVersion) {
    if(oldVersion.size() == 0){
        return std::string("[") + newVersion + "]";
    }else if(newVersion.size() == 0){
        return std::string("(") + oldVersion + ")";
    }
    auto l = getLCS(oldVersion,newVersion);
    auto w = l[0];
    auto os = l[1];
    auto ns = l[2];
    return oldVersion.substr(os,w);
    /*return displayDiff(oldVersion.substr(0,os),newVersion.substr(0,ns))
        + oldVersion.substr(os,w)
        + displayDiff(oldVersion.substr(os+w,std::string::npos),newVersion.substr(ns+w,std::string::npos));*/
}
