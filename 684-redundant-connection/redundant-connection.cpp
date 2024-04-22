class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int,vector<int>>mp;
        int n=edges.size();
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            ans=edges[i];
            vector<int>vis(n+1,0);
            int u=edges[i][0];
            int v=edges[i][1];
            queue<int>q;
            q.push(1);
            vis[1]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:mp[node]){
                    if((node==u && it==v) || (node==v && it==u)){
                        continue;
                    }
                    else if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            bool flag=false;
            for(int i=1;i<=n;i++){
                if(!vis[i])flag=true;
            }
            if(flag==false)break;
        }
        return ans;
    }
};