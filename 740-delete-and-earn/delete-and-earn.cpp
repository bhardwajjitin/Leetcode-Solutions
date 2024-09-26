class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>umap;
        for(auto it:nums){
            umap[it]++;
        }
        vector<int>arr;
        for(auto it:umap){
            arr.push_back(it.first);
        }
        sort(arr.begin(),arr.end());
        vector<int>dp(arr.size(),0);
        dp[0] = umap[arr[0]]*arr[0];
        int maxi=dp[0];
        for(int i=1;i<arr.size();i++){
            int temp=arr[i]-2;
            int ind=upper_bound(arr.begin(),arr.end(),temp)-arr.begin();
            ind-=1;
            int curr=umap[arr[i]]*arr[i],prev=dp[i-1];
            if(ind==-1){
                dp[i]=max(curr,prev);
                continue;
            }
            curr=curr+dp[ind];
            dp[i] = max({curr,prev,dp[i]});
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};