class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt=0;
        int j=0,i=0;
        while(j<nums.size()){
            if(nums[j]==0){
                cnt+=j-i+1;
                j++;
            }
            else{
                j++;
                i=j;
            }
        }
        return cnt;
    }
};