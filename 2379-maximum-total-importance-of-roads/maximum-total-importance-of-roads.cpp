class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n);
        long long sum=0;
        for(int i=0;i<roads.size();i++){
          int u=roads[i][0];
          int v=roads[i][1];
          indegree[u]++;
          indegree[v]++;
        }
        priority_queue<int>pq(indegree.begin(),indegree.end());
        while(!pq.empty()){
          long long top=pq.top();
          pq.pop();
          sum+=top*n;
          n--;
        }
        return sum;
    }
};