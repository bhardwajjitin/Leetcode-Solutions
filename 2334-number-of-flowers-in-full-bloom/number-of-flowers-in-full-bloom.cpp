class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,long long>umap;
        for(auto it:flowers){
            int start=it[0];
            int end=it[1];
            umap[start]+=1;
            umap[end+1]-=1;
        }
        for(auto it:people){
            if(umap.find(it)==umap.end()){
                umap[it]=0;
            }
        }
        long long sum=0;
        for(auto it:umap){
            int key=it.first;
            int value=it.second;
            sum+=value;
            umap[key]=sum;
        }
        vector<int>ans;
        for(auto it:people){
            int val=umap[it];
            ans.push_back(val);
        }
        return ans;
    }
};