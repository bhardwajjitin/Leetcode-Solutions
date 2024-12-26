class Solution {
    private:
    int solve(vector<int>&nums,int ind,int target){
        if(ind>=nums.size()){
            if(target==0)return 1;
            return 0;
        }
        int plus=solve(nums,ind+1,target+nums[ind]);
        int sub=solve(nums,ind+1,target-nums[ind]);
        return plus+sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,target);
    }
};