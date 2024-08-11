class Solution {
    private:
    int solve(int node,vector<int>adj[],vector<int>&sum,vector<int>&vis){
        vis[node]=1;
        int res=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                res+=solve(it,adj,sum,vis);
            }
        }
        sum[node]+=res;
        return res;
    }
    void check(int node,vector<int>adj[],vector<int>&sum,vector<int>&res,int&cnt){
        set<int>st;
        res[node]=1;
        for(auto it:adj[node]){
            if(!res[it]){
                st.insert(sum[it]);
                check(it,adj,sum,res,cnt);
            }
        }
        if(st.size()==1 || st.size()==0)cnt++;
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        vector<int>sum(n,0);
        vector<int>vis(n,0);
        solve(0,adj,sum,vis);
        vector<int>res(n,0);
        check(0,adj,sum,res,cnt);
        return cnt;
    }
};

