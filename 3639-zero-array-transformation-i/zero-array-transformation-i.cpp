class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        map<int,int>umap;
        for(auto it:queries){
            int start=it[0];
            int end=it[1];
            umap[start]--;
            umap[end+1]++;
        }
    
        if(nums[0]>abs(umap[0])){
            return false;
        }
        for(int i=1;i<nums.size();i++){
            umap[i]=umap[i-1]+umap[i];
            if(nums[i]>abs(umap[i]))return false;
        }
        return true;
    }
};