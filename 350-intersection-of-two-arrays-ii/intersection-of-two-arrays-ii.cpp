class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>umap1;
        unordered_map<int,int>umap2;
        for(auto it:nums1){
          umap1[it]++;
        }
        for(auto it:nums2){
          umap2[it]++;
        }
        vector<int>ans;
        for(auto it:umap1){
          int key=it.first;
          int value=it.second;
          if(umap2.find(key)!=umap2.end()){
            while(min(umap2[key],umap1[key])>0){
              ans.push_back(key);
              umap2[key]--;
              umap1[key]--;
            }
          }
        }
        return ans;
    }
};