class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
       int cnt=0;
       unordered_map<int,int>umap;
       long long ans=0;
       umap[0]=1;
       for(int i=0;i<nums.size();i++){
        if(nums[i]%modulo==k){
            cnt++;
        }
        int remainder=cnt%modulo;
        remainder=(remainder+modulo)%modulo;
        int target=(remainder + modulo - k)%modulo;
        if(umap.find(target)!=umap.end()){
            ans+=umap[target];
        }
        umap[remainder]++;
       }
        return ans;
    }
};