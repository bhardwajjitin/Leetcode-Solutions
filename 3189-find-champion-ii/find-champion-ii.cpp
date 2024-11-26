class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>arr(n,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            arr[v]++;
        }
        int cnt=0;
        int ans;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                ans=i;
                cnt++;
            }
        }
        return cnt>1?-1:ans;
    }
};