class Solution {
  private:
  int solve(vector<int>&nums,int ele){
          int ans=-1;
          int low=0;
          int high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)>>1;
          if(nums[mid]>=ele){
            ans=mid;
            high=mid-1;
          }
          else{
              low=mid+1;
          }
    }
    return ans;
  }
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=nums[nums.size()-1];
        while(maxi>=0){
          int ind=solve(nums,maxi);
          if(nums.size()-ind==maxi)return maxi;
          maxi--;
        }
        return -1;
    }
};