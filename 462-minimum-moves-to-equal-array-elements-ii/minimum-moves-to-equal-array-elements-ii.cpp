class Solution {
public:
    int minMoves2(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int mid;
      if(nums.size()%2!=0){
        mid=nums.size()/2;
      }
      else{
        mid=(nums.size()+1)/2;
      }
        int sum=0;
        int ans=nums[mid];
  
        for(auto it:nums){
          sum+=abs(it-ans);
        }
        return sum;
    }
};