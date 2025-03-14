class Solution {
    private:
    bool solve(int mid,long long k,vector<int>&candies){
          for(int i=0;i<candies.size();i++){
            int candy=candies[i];
            int total=candy/mid;
            k-=total;
          }
          return k<=0?true:false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans=0;
        int low=1;
        int high=*max_element(candies.begin(),candies.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(mid,k,candies)){
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