class Solution {
  private:
  int solve(vector<int>&arr,int x){
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
      int mid=(low+high)>>1;
      if(arr[mid]==x)return mid;
      if(arr[mid]<x)low=mid+1;
      else high=mid-1;
    }
    return INT_MAX;
  }
  int solve1(vector<int>&arr,int x,int low,int high){
    // int high=0;
    // int low=arr.size()-1;
    while(low>=high){
      int mid=(low+high)>>1;
      if(arr[mid]==x)return mid;
      if(arr[mid]<x)low=mid-1;
      else high=mid+1;
    }
    return INT_MAX;
  }
public:
    int minOperations(vector<int>& nums, int x) {
        vector<int>pre(nums.size()),suff(nums.size());
        pre[0]=nums[0];
        suff[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
          pre[i]=pre[i-1]+nums[i];
        }
        for(int i=nums.size()-2;i>=0;i--){
          suff[i]=suff[i+1]+nums[i];
        }
        int first=solve(pre,x);
        if(first!=INT_MAX)first+=1;
        int second=solve1(suff,x,nums.size()-1,0);
        if(second!=INT_MAX)second=nums.size()-second;
        int third=INT_MAX;
        for(int i=0;i<pre.size();i++){
          if(pre[i]>x)continue;
          int t1=i+1;
          int t2=solve1(suff,x-pre[i],nums.size()-1,t1);
          if(t2!=INT_MAX){
            int temp=t1+(pre.size()-t2);
            third=min(third,temp);
          }
        }
        return min({first,second,third})==INT_MAX?-1:min({first,second,third});
    }
};