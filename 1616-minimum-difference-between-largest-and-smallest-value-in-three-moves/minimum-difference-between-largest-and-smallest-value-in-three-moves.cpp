class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1)return nums[n];
        if(n==2 || n==3 || n==4)return 0;
        int temp=nums[n-4]-nums[0];
        int temp1=nums[n-1]-nums[3];
        int temp2=nums[n-2]-nums[2];
        int temp3=nums[n-3]-nums[1];
        return min({temp,temp1,temp2,temp3});
    }
};