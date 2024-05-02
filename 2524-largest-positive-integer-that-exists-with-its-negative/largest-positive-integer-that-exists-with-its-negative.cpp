class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        while(i!=j){
          int temp=(-1)*nums[i];
          if(temp==nums[j]){
            return nums[j];
          }
          else if(temp>nums[j]){
            i++;
          }
          else{
            j--;
          }
        }
        return -1;
    }
};