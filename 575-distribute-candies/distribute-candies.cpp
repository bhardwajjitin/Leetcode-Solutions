class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int>umap;
        for(auto it:candyType)umap[it]++;
        int cntunique=umap.size();
        int half=candyType.size()/2;
        if(cntunique<=half)return cntunique;
        return half;
    }
};