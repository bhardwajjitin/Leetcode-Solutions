class Solution {
public:
    long long maximumTotalDamage(vector<int>& p) {
        // sort(power.begin(),power.end());
        unordered_map<long long,long long>umap;
        for(auto it:p)umap[it]++;

        vector<long long>power;
        for(auto it:umap){
            power.push_back(it.first);
        }
        sort(power.begin(),power.end());
        vector<long long>dp(power.size()+2,-1);
        dp[0] = umap[power[0]]*power[0];

        for(int current = 1 ; current < power.size() ; current++){
            int value=power[current]-3;
            int ind=upper_bound(power.begin(),power.end(),value)-power.begin();
            ind-=1;
            long long useCurrent = umap[power[current]]*power[current] , notUseCurrent = dp[current-1];
            if(ind==-1){
                dp[current]=max(useCurrent,notUseCurrent);
                continue;
            }
            useCurrent = useCurrent+dp[ind];
            dp[current] = max({useCurrent,notUseCurrent,dp[current]});
        }
        long long maxi=LLONG_MIN;
        for(auto it:dp){
            maxi=max(it,maxi);
        }
        return maxi;
    }
};