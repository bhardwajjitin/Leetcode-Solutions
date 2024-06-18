class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        unordered_map<int,int>umap;
        for(int i=0;i<diff.size();i++){
          umap[diff[i]]=max(umap[diff[i]],profit[i]);
        }
        sort(diff.begin(),diff.end());
        int ans=0;
        vector<long long>res(diff.size()+10);
        res[0]=umap[diff[0]];
        for(int i=1;i<diff.size();i++){
          res[i]=max(res[i-1],(long long)umap[diff[i]]);
        }
        for(int i=0;i<worker.size();i++){
          int temp=worker[i];
          int ind=upper_bound(diff.begin(),diff.end(),temp)-diff.begin();
          if(ind!=0){
          ans+=res[ind-1];
          }
        }
        return ans;
    }
};