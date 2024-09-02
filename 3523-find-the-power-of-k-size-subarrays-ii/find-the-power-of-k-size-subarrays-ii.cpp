class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1)return nums;
        int j=1;
        int i=0;
        vector<int>ans;
        while(j<nums.size()){
            if(nums[j]!=nums[j-1]+1){
                while(i<j && i<=nums.size()-k){
                    ans.push_back(-1);
                    i++;
                }
            }
            if(nums[j]==nums[j-1]+1){
                if(j-i+1==k){
                    ans.push_back(nums[j]);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};