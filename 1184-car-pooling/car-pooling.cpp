class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int>linemap;
        for(auto it:trips){
           linemap[it[1]]+=it[0];
           linemap[it[2]]-=it[0];
        }
        long long sum=0;
        for(auto temp:linemap){
            sum+=linemap[temp.first];
            if(sum>capacity)return false;
        }
        return true;
    }
};