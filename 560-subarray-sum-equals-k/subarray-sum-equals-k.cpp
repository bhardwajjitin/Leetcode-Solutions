class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n+1);
        unordered_map<int,int>umap;
        pre[0]=0;
        umap[0]++;
        int cnt=0;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
            if(umap.find(pre[i+1]-k)!=umap.end()){
                cnt+=umap[pre[i+1]-k];
            }
            umap[pre[i+1]]++;
        }
       return cnt;
    }
};