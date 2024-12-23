class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        int i=0;
        int j=0;
        int ans=INT_MIN;
        while(j<nums.size()){
            umap[nums[j]]++;
            while(i<j && umap[nums[j]]>k){
                umap[nums[i]]--;
                if(umap[nums[i]]==0){
                    umap.erase(nums[i]);
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};