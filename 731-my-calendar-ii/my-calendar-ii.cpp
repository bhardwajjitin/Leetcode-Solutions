class MyCalendarTwo {
    map<long long,long long>umap;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        umap[startTime]+=1;
        umap[endTime]-=1;
        long long sum=0;
        for(auto it:umap){
            sum+=it.second;
            if(sum>=3){
                umap[startTime]-=1;
                umap[endTime]+=1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */