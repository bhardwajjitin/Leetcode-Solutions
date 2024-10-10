class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxand=nums[0];
        for(auto it:nums){
            maxand=max(maxand,it);
        }
        int maxele=*max_element(nums.begin(),nums.end());
        int size=0;
        int maxsize=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxele){
                size++;
                maxsize=max(maxsize,size);
            }
            else{
                size=0;
            }
        }
        return maxsize;
    }
};