#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

int end, spd;
struct file{
    int index;
    int start;
    int size;
    int done;
    
    file(int index,int start,int size):index{index},start{start},size{size}{
        done = 0;
    }
    bool operator<(const file& other) const{
        return start < other.start;
    }
    bool canUpload(int now, int sLeft){
        return now + size/spd <= end && sLeft >= size; 
    }
};
bool bySize(file& a, file& b){
    if(a.done == b.done)
        return a.size < b.size;
    else
        return b.done;
}
bool byIndex(file& a, file& b){
    return a.index < b.index;
}
bool byDone(file&a, file&b){
    return a.done < b.done;
}
std::vector<int> fileSyncOrder(std::vector<std::vector<int>> fs, int storageLimit, int uploadSpeed, int duration) {
    end = duration;
    spd = uploadSpeed;
    
    std::vector<file> files;
    int l = fs.size();
    for(int i=0;i<l;++i){
        files.push_back(file(i,fs[i][1],fs[i][0]));
    }
    std::sort(files.begin(),files.end());
    
    int now = files[0].start;
    
    std::list<file&> queue;
    queue.push_back(files[0]);
    int done = 0;
    while(1){
        std::sort(files.begin(),files.end(),bySize);
        auto& f = files.front();
        now += f.size / uploadSpeed;
        storageLimit -= f.size;
        f.done = ++done;
        if(done == files.size())
            break;
    }
    std::vector<int> ret;
    std::sort(files.begin(),files.end(),byDone);
    for(auto& f : files){
        if(f.done ==0)
            continue;
        ret.push_back(f.index);
    }
    return ret;
}
