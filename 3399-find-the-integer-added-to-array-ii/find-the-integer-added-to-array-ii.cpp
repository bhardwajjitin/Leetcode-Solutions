class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>umap,umap1;
        for(auto it:nums1){
            umap[it]++;
        }
        for(auto it:nums2){
            umap1[it]++;
        }
       set<int>st;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int diff=nums2[j]-nums1[i];
                st.insert(diff);
            }
        }
        int ret=-1;
      for(auto temp:st){
          int cnt=0;
          unordered_map<int,int>ans=umap;
          unordered_map<int,int>res=umap1;
         for(auto j:umap1){
                while(ans.find(j.first-temp)!=ans.end() && j.second>0){
                    ans[j.first-temp]--;
                    j.second--;
                    if(ans[j.first-temp]==0){
                      ans.erase(j.first-temp);
                    }
                    cnt++;
                }
            }
            if(cnt==nums1.size()-2)return temp;
       }
        return ret;
    }
};