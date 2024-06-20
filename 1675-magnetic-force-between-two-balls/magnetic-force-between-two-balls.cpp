class Solution {
  private:
  bool solve(vector<int>&posi,int dis,int m){
    int st=posi[0];
    m--;
    for(int i=1;i<posi.size();i++){
      if(abs(posi[i]-st)>=dis){
        st=posi[i];
        m--;
      }
      if(m==0)return true;
    }
    return false;
  }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=INT_MAX;
        for(int i=1;i<n;i++){
          low=min(low,position[i]-position[i-1]);
        }
        int high=position[n-1]-position[0];
        int ans=-1;
        while(low<=high){
          int mid=(low+high)>>1;
          if(solve(position,mid,m)){
            ans=mid;
            low=mid+1;
          }
          else{
            high=mid-1;
          }
        }
        return ans;
    }
};