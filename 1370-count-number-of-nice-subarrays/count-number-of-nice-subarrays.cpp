class Solution {
  private:
  int almost(vector<int>&nums,int k){
    int i=0;
    int j=0;
    int sum=0;
    int cnt=0;
    while(j<nums.size()){
      sum+=(nums[j]%2);
      if(sum<=k)cnt+=j-i+1;
      else{
        while(i<=j && sum>k){
          sum-=(nums[i]%2);
          i++;
        }
        if(sum<=k)cnt+=j-i+1;
      }
      j++;
    }
    return cnt;
  }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return almost(nums,k)-almost(nums,k-1);
    }
};