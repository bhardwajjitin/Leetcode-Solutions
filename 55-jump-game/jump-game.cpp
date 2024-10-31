class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)return true;
        // int j=nums.size()-1;
        // int i=j-1;
        // while(i>=0){
        //     if(j-i<=nums[i]){
        //         j=i;
        //     }
        //     i--;
        // }
        // if(j==0)return true;
        // return false;
        int maxindex=0;
        int start=0;
        while(start<nums.size() && start<=maxindex){
            maxindex=max(maxindex,start+nums[start]);
            start++;
        }
        if(maxindex>=nums.size()-1)return true;
        return false;
    }
};