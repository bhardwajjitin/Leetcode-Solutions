class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev=nums[0];
        int prev1=nums[1];
        int max_ans=2;
        int length=2;
        for(int i=2;i<nums.size();i++){
            if(prev+prev1==nums[i]){
               length++;
               max_ans=max(max_ans,length);
            }
            else{
                length=2;
            }
            prev=prev1;
            prev1=nums[i];
        }
        return max_ans;
    }
};