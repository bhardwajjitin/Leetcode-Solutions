class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int>prefix(nums.size()+1);
        prefix[0]=0;
        for(int i=1;i<=nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        unordered_map<int,int>umap;
        int minlen=INT_MIN;
        for(int i=0;i<=nums.size();i++){
            int temp=2*prefix[i]-i;
            if(umap.find(temp)!=umap.end()){
                minlen=max(minlen,i-umap[temp]);
            }
            else{
            umap[2*prefix[i]-i]=i;
            }
        }
        return minlen==INT_MIN?0:minlen;
    }
};