class comp{
    public:
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b){
         if(a.first == b.first) {
            if (a.second.first == b.second.first) {
                return a.second.second<b.second.second;
            }
            return a.second.first>b.second.first;
        }
        return a.first<b.first;
    }
};
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,pair<int,int>>>arr;
        for(int i=0;i<times.size();i++){
            int incoming=times[i][0];
            int outgoing=times[i][1];
            arr.push_back({incoming,{0,i}});
            arr.push_back({outgoing,{1,i}});
        }
        sort(arr.begin(),arr.end(),comp());
        unordered_map<int,int>umap;
        multiset<int>ml;
        for(int i=0;i<=1e4;i++){
            ml.insert(i);
        }
        for(auto it:arr){
            int type=it.second.first;
            int person=it.second.second;
            if(type==0){
                if(person==targetFriend)return *ml.begin();
                umap[person]=*ml.begin();
                ml.erase(*ml.begin());
            }
            if(type==1){
                ml.insert(umap[person]);
            }
        }
        return -1;
    }
};