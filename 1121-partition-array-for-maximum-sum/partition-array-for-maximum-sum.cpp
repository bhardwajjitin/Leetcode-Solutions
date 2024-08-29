class Solution {
    private:
    long long solve(vector<int>&arr,int i,int n,int k,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        long long mini=INT_MIN;
        long long maxi=arr[i];
        for(int j=i;j<min(i + k, n);j++){
            if(maxi<arr[j]){
                maxi=arr[j];
            }
            long long sum=maxi*(j-i+1)+solve(arr,j+1,n,k,dp);
            mini=max(mini,sum);
        }
        return dp[i]=mini;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        // vector<int>dp(n,-1);
        // return solve(arr,0,n,k,dp);
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            long long mini=INT_MIN;
            long long maxi=arr[i];
            for(int j=i;j<min(i + k, n);j++){
                if(maxi<arr[j]){
                    maxi=arr[j];
                }
                long long sum=maxi*(j-i+1)+dp[j+1];
                mini=max(mini,sum);
            }
            dp[i]=mini;
        }
        return dp[0];
    }
};