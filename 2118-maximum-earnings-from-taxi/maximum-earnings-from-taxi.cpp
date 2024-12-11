class Solution {
    private:
    int getind(vector<vector<int>>&rides,int val,int low){
        int high=rides.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(rides[mid][0]>=val){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    long long solve(vector<vector<int>>&rides,vector<long long>&dp,int ind){
        if(ind>=rides.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        long long notpick=solve(rides,dp,ind+1);
        long long pick=(long long)rides[ind][1]-(long long)rides[ind][0]+(long long)rides[ind][2];
        int nextpass=getind(rides,rides[ind][1],ind+1);
        if(nextpass!=-1){
            pick+=solve(rides,dp,nextpass);
        }
        return  dp[ind]=max(pick,notpick);
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long>dp(rides.size(),-1);
        sort(rides.begin(),rides.end());
        return solve(rides,dp,0);
    }
};