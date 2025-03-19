class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        int i=0;
        while(i<nums.size()-2){
            if(nums[i]==0){
                nums[i]=!nums[i];
                nums[i+1]=!nums[i+1];
                nums[i+2]=!nums[i+2];
                cnt++;
            }
            i++;
        }
        for(auto it:nums){
            if(it==0)return -1;
        }
        return cnt;
    }
};