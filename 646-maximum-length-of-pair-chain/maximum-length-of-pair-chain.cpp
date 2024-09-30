class Solution {
    int solve(vector<vector<int>>&pairs,int ind,int prev){
        if(ind>=pairs.size())return 0;

        int notpick=solve(pairs,ind+1,prev);
        int pick=0;
        if(prev==-1 || pairs[prev][1]<pairs[ind][0]){
            pick=1+solve(pairs,ind+1,ind);
        }
        return max(pick,notpick);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort(pairs.begin(),pairs.end());
        // return solve(pairs,0,-1);

        // tabulation
        int n=pairs.size();
        // vector<vector<int>>dp(pairs.size()+1,vector<int>(pairs.size()+1,0));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=-1;j<n;j++){
        //         int notpick=dp[i+1][j+1];
        //         int pick=0;
        //         if(j==-1 || pairs[j][1]<pairs[i][0]){
        //         pick=1+dp[i+1][i+1];
        //         }
        //         dp[i][j+1]=max(pick,notpick);
        //     }
        // }
        // return dp[0][0];
        // greedy solution
    sort(pairs.begin(),pairs.end(),[](const vector<int>& a,const vector<int>& b) {return a[1]<b[1];});
     int cnt=1;
     int last=pairs[0][1];
     for(int i=1;i<n;i++){
        if(pairs[i][0]>last){
            last=pairs[i][1];
            cnt++;
        }
     }
     return cnt;
    }
};