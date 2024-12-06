class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int>umap;
        for(auto it:banned){
            umap[it]++;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
           if(umap.find(i)==umap.end() && maxSum>=i){
            maxSum-=i;
            cnt++;
           }
        }
        return cnt;
    }
};