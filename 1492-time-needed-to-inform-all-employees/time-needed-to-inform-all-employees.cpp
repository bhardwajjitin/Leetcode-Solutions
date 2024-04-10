class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(i!=headID){
               int u=manager[i];
               adj[u].push_back(i);
            }
        }
        int ans=0;
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            ans=max(ans,top.second);
            for(auto it:adj[top.first]){
                int temp=top.second+informTime[top.first];
                q.push({it,temp});
            }
        }
        return ans;
    }
};