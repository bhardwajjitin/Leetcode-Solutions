class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>res=arr;
        vector<int>ans;
        if(arr.size()==0)return {};
        unordered_map<int,int>umap;
        sort(res.begin(),res.end());
        int rank=1;
        umap[res[0]]=1;
        for(int i=1;i<res.size();i++){
            if(res[i]!=res[i-1])rank++;
            umap[res[i]]=rank;  
        }
        for(int i=0;i<arr.size();i++){
            ans.push_back(umap[arr[i]]);
        }
        return ans;
    }
};