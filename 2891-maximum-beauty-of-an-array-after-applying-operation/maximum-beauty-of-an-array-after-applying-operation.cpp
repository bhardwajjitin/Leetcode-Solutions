class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it-k]++;
            mp[it+k+1]--;
        }
        int ans=0;
        int sum=0;
        for(auto it:mp){
            sum+=it.second;
            ans=max(ans,sum);
        }
        return ans;
    }
};