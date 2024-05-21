class Solution {
public:
    bool canCross(vector<int>& stones) {
      if(stones[1]!=1)return false;
        unordered_map<int,int>umap;
        for(int i=0;i<stones.size();i++){
          umap[stones[i]]=i;
        }
        set<pair<int,int>>q;
        q.insert({1,1});
        while(!q.empty()){
           auto it=*q.begin();
           q.erase(*q.begin());
           int ind=it.first;
           int jump=it.second;
           if(ind==stones.size()-1){
            return true;
           }
           if(umap.find(stones[ind]+jump-1)!=umap.end() && umap[stones[ind]+jump-1]>ind){
            int index=umap[stones[ind]+jump-1];
            q.insert({index,jump-1});
           }
           if(umap.find(stones[ind]+jump)!=umap.end() && umap[stones[ind]+jump]>ind){
            int index=umap[stones[ind]+jump];
            q.insert({index,jump});
           }
           if(umap.find(stones[ind]+jump+1)!=umap.end() && umap[stones[ind]+jump+1]>ind){
            int index=umap[stones[ind]+jump+1];
            q.insert({index,jump+1});
           }
        }
        return false;
    }
};