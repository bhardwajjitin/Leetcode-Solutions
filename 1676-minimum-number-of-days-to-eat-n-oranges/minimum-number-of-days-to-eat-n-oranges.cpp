class Solution {
public:
    int minDays(int n) {
    set<pair<int,int>>pq;
    pq.insert({0,n});
    int ans=-1;
    while(true){
        auto it=*pq.begin();
        pq.erase(*pq.begin());
        int temp=it.second;
        int day=it.first;
        if(temp==0){
            ans=day;
            break;
        }
        pq.insert({day+1,temp-1});
        if(temp%2==0){
            pq.insert({day+1,temp/2});
        }
        if(temp%3==0){
            pq.insert({day+1,temp/3});
        }
    }
    return ans;
    }
};