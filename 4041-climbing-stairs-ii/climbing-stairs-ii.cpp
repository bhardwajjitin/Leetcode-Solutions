class Solution {
    private:
    int solve(int curr,vector<int>&costs,vector<int>&dp){
        if(curr==costs.size()-1)return 0;
        if(dp[curr+1]!=-1)return dp[curr+1];
        int first=INT_MAX,second=INT_MAX,third=INT_MAX;
        if(curr+1<costs.size()){
            first=costs[curr+1]+1+solve(curr+1,costs,dp);
        }
        if(curr+2<costs.size()){
            second=costs[curr+2]+4+solve(curr+2,costs,dp);
        }
        if(curr+3<costs.size()){
            third=costs[curr+3]+9+solve(curr+3,costs,dp);
        }
        return dp[curr+1]=min({first,second,third});
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        // vector<int>dp(n+1,-1);
        // return solve(-1,costs,dp);
        vector<int> dp(n+1, INT_MAX);
        dp[n-1] = 0;
        
        for (int curr = n-2; curr >= -1; curr--) {
            int first = INT_MAX, second = INT_MAX, third = INT_MAX;
            if (curr+1 < n && dp[curr+1] != INT_MAX) {
                first = costs[curr+1] + 1 + dp[curr+1];
            }
            if (curr+2 < n && dp[curr+2] != INT_MAX) {
                second = costs[curr+2] + 4 + dp[curr+2];
            }
            if (curr+3 < n && dp[curr+3] != INT_MAX) {
                third = costs[curr+3] + 9 + dp[curr+3];
            }
            if (curr >= 0) {
                dp[curr] = min({first, second, third});
            } else {
                return min({first, second, third});
            }
        }
        return dp[0];
    }
};