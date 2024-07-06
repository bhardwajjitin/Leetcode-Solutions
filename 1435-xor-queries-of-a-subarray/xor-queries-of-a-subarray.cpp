class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        int m=queries.size();
        vector<int>res(n);
        vector<int>ans(m);
        res[0]=arr[0];
        for(int i=1;i<n;i++){
          res[i]=arr[i]^res[i-1];
        }
        for(int i=0;i<m;i++){
          int u=queries[i][0];
          int v=queries[i][1];
          if(u!=0){
          ans[i]=res[v]^res[u-1];
          }
          else
          ans[i]=res[v];
        }
        return ans;
    }
};