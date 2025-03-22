class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0),indegree(n,0);
        int count=0;
        vector<int> adjlist[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
            indegree[u]++;
        }
     
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int cntnode=0;
                visited[i]=1;
                queue<int>q;
                q.push(i);
                int indegreesum=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    indegreesum+=indegree[node];
                    cntnode++;
                    for(auto it:adjlist[node]){
                        if(!visited[it]){
                        q.push(it);
                        visited[it]=1;
                        }
                    }
                }
                if(indegreesum==(cntnode*(cntnode-1))/2){
                    count++;
                }
            }
        }
        return count;
    }
};