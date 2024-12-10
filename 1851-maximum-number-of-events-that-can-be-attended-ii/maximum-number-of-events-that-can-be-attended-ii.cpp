class Solution {
    private:
    int getind(vector<tuple<int,int,int>>&res,int val,int low){
        int high = res.size() - 1, nextJob = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (get<0>(res[mid]) > val) {
                nextJob = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return nextJob;
    }
    int solve(int ind,int attend,int k,vector<tuple<int,int,int>>&res,vector<vector<int>>&dp){
        if(attend>=k || ind>=res.size())return 0;

        if(dp[ind][attend]!=-1)return dp[ind][attend];
        int notpick=solve(ind+1,attend,k,res,dp);
        int pick=get<2>(res[ind]);
        int nextind=getind(res,get<1>(res[ind]),ind+1);
        if(nextind!=-1){
            pick+=solve(nextind,attend+1,k,res,dp);
        }
        return dp[ind][attend]=max(pick,notpick);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        vector<tuple<int,int,int>>res;
        for(auto it:events){
            res.push_back({it[0],it[1],it[2]});
        }
        sort(res.begin(),res.end());
        vector<vector<int>>dp(res.size(),vector<int>(k+1,-1));
        return solve(0,0,k,res,dp);
    }
};