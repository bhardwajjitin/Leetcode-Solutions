class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        unordered_map<int,long long>umap;
        umap[abs(k-1)%k]=0;
        vector<long long>pre(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++){
            pre[i]=pre[i-1]+(long long)nums[i-1];
        }
        long long maxi=LLONG_MIN;
        for(int i=0;i<nums.size();i++){
            int mod=i%k;
           if (umap.find(mod) != umap.end()) {
                long long subarraySum = pre[i + 1] - umap[mod];
                maxi = max(maxi, subarraySum);
            }
            if (umap.find(mod) == umap.end()) {
                umap[mod] = pre[i + 1];
            } else {
                umap[mod] =umap[mod]<=pre[i + 1]?umap[mod]:pre[i+1];
            }
        }
        return maxi;
    }
};