class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int>umap;
        int n=word.size();
        int i=0;
        int j=1;
        while(i<=n-k){
          string temp=word.substr(i,k);
          umap[temp]++;
          i=j*k;
          j++;
        }
        int times=n/k;
        int maxi=0;
        for(auto it:umap){
          int val=it.second;
          maxi=max(maxi,val);
        }
        return times-maxi;
    }
};