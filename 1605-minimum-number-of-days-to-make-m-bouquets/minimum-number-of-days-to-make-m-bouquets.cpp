class Solution {
  private:
  bool check(int i,vector<int>&bloom,int m,int k){
    int temp=k;
    for(int j=0;j<bloom.size();j++){
      if(bloom[j]<=i)temp--;
      else{
        temp=k;
      }
      if(temp==0){
        m--;
        temp=k;
      }
      if(m==0)return true;
    }
    return false;
  }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini=*min_element(bloomDay.begin(),bloomDay.end());
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());
        // brute force approach
        // for(int i=mini;i<=maxi;i++){
        //   if(check(i,bloomDay,m,k))return i;
        // }
        // binary search approach
        int ans=-1;
        while(mini<=maxi){
          int mid=(mini+maxi)>>1;
          if(check(mid,bloomDay,m,k)){
            ans=mid;
            maxi=mid-1;
          }
          else mini=mid+1;
        }
        return ans;
    }
};