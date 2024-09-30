class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int>pre(nums.size());
        unordered_map<int,int>umap;
        pre[0]=nums[0];
        umap[0]=-1;
        if(umap.find(pre[0]%k)==umap.end())
        umap[pre[0]%k]=0;
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
            if(umap.find(pre[i]%k)!=umap.end()){
                if(i-umap[pre[i]%k]>=2){
                    return true;
                }
                else 
                    continue;
            }
            else{
            umap[pre[i]%k]=i;
            }
        }
        return false;
    }
};