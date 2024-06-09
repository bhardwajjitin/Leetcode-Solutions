class Solution {
    private:
    int solve(vector<int>&rew,int ind,int n,int curr,vector<vector<int>>&dp,int range){
        if(ind>=n){
            return 0;
        }    
        if(dp[ind][curr]!=-1)return dp[ind][curr];
        int exc=solve(rew,ind+1,n,curr,dp,range);
        int inc=0;
        if(curr<rew[ind] && curr+rew[ind]<=range){
            inc=rew[ind]+solve(rew,ind+1,n,curr+rew[ind],dp,range);
        }
        return dp[ind][curr]=max(inc,exc);
    }
    
public:
    int maxTotalReward(vector<int>& rew) {
        int n=rew.size();
//         memo
        sort(rew.begin(),rew.end());
        long long sum=0;
        for(auto it:rew)sum+=it;
        
        int maxi=rew[n-1];
        int range;
        if(maxi<=sum){
            range=maxi;
        }
        else{
            range=sum;
        }
        // vector<vector<int>>dp(n,vector<int>(range+1,-1));
        // return solve(rew,0,n,0,dp,range);
//         tabu
        //  vector<vector<int>>dp(n,vector<int>(range+1,0));
        // for(int i=0;i<=range;i++){
        //     if(i<rew[n-1]){
        //         dp[n-1][i]=rew[n-1];
        //     }
        // }
        // for(int ind=n-2;ind>=0;ind--){
        //     for(int curr=0;curr<=range;curr++){
        //         int exc=dp[ind+1][curr];
        //         int inc=0;
        //         if(curr<rew[ind] && curr+rew[ind]<=range){
        //              inc=rew[ind]+dp[ind+1][curr+rew[ind]];
        //         }
        //         dp[ind][curr]=max(inc,exc);
        //      }
        // }
        // return dp[0][0];
        
//         space 
        vector<int>prev(range+1,0),cur(range+1,0);
        for(int i=0;i<=range;i++){
            if(i<rew[n-1]){
                prev[i]=rew[n-1];
            }
        }
        for(int ind=n-2;ind>=0;ind--){
            for(int curr=0;curr<=range;curr++){
                int exc=prev[curr];
                int inc=0;
                if(curr<rew[ind] && curr+rew[ind]<=range){
                     inc=rew[ind]+prev[curr+rew[ind]];
                }
                cur[curr]=max(inc,exc);
             }
            prev=cur;
        }
        return prev[0];
    }
};