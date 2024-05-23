class Solution {
  private:
  int solve(vector<int>&nums,int k,int ind,map<int,int>&ds){
    if(ind>=nums.size()){
      return 1;
    }
    int left=solve(nums,k,ind+1,ds);
    int right=0;
    if(ds[(nums[ind]+k)] == 0 && ds[(nums[ind]-k)]==0){
      ds[nums[ind]]++;
      right=solve(nums,k,ind+1,ds);
      ds[nums[ind]]--;
    }
    return left+right;
  }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
       map<int,int>ds;
       return solve(nums,k,0,ds)-1;
    }
};