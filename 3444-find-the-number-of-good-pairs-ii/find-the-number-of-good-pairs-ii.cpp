class Solution {
    private:
    set<int>solve(long long maxi){
        set<int>ans;
        for(int i=1;i<=sqrt(maxi);i++){
            if(maxi%i==0){
                ans.insert(i);
                ans.insert(maxi/i);
            }
        }
        return ans;
    }
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long cnt=0;
        unordered_map<int,int>umap;
        for(auto it:nums2){
            umap[it]++;
        }
        
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%k==0){
                int maxi=nums1[i]/k;
                set<int>ans=solve(maxi);
                ans.insert(maxi);
                ans.insert(1);
                for(auto it:ans){
                    if(umap.find(it)!=umap.end()){
                        cnt+=umap[it];
                    }
                }
            }
            else{
                continue;
            }
        }
        return cnt;
    }
};