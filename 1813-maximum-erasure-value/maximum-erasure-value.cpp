class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int>umap;
        int i=0;
        int j=0;
        int maxi=INT_MIN;
        while(j<nums.size()){
                while(i<j && umap.find(nums[j])!=umap.end()){
                    sum-=nums[i];
                    umap[nums[i]]--;
                    if(umap[nums[i]]==0){
                        umap.erase(nums[i]);
                    }
                    i++;
                }
            umap[nums[j]]++;
            sum+=nums[j];
            j++;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};