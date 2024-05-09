class Solution {
public:
    int minMoves(vector<int>& nums) {
      int sum=0;
      int mini=*min_element(nums.begin(),nums.end());
      for(auto it:nums){
          sum+=it-mini;
      }
      return sum;
    }
};