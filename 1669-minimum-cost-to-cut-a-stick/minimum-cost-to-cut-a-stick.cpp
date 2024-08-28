class Solution {
    private:
    int solve(vector<int>&cuts,int i,int j,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=1e9;
        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1]+solve(cuts,i,k-1,dp)+solve(cuts,k+1,j,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int c=cuts.size();
        // vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        // return solve(cuts,1,cuts.size()-2,dp);
        vector<vector<int>>dp(c+1,vector<int>(c+1,0));

        for(int i=cuts.size()-1;i>=1;i--){
            for(int j=1;j<cuts.size()-1;j++){
                if(i>j)continue;
                int mini=INT_MAX;
                for(int k=i;k<=j;k++){
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][cuts.size()-2];
    }
};