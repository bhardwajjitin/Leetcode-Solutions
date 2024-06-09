class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int>dp(n,-1);
        int maxi=INT_MIN;
        for(int i=n-1;i>=n-k;i--){
            dp[i]=energy[i];
        }
        for(int i=n-k-1;i>=0;i--){
            dp[i]=energy[i]+dp[i+k];
        }
        for(auto it:dp){
            maxi=max(maxi,it);
        }
        return maxi;
    }
};