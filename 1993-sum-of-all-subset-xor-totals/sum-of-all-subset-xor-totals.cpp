class Solution {
  private:
  void solve(vector<int>&nums,int&sum,int res,int ind){
    if(ind<0){
      sum+=res;
      return;
    }
    solve(nums,sum,res,ind-1);
    res^=nums[ind];
    solve(nums,sum,res,ind-1);
  }
public:
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        solve(nums,sum,0,nums.size()-1);
        return sum;
    }
};