class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>umap;
        int n=nums.size();
        int max_index=INT_MIN;
        vector<int>last_index(nums.size());
        for(int i=0;i<nums.size();i++){
            if(umap.find(nums[i])==umap.end()){
                last_index[i]=-1;
            }
            else{
                last_index[i]=umap[nums[i]];
            }
            umap[nums[i]]=i;
            max_index=max(max_index,last_index[i]);
        }
        if(max_index==-1)return 0;

        return ceil(max_index/3)+1;
    }
};