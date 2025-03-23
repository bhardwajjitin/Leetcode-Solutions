class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod=1000000007;
        vector<pair<long long,int>>res(n,{LLONG_MAX,0});
        priority_queue<tuple<long long,int>,vector<tuple<long long,int>>,greater<>>pq;
        pq.push({0,0});
        vector<pair<int,int>>adjlist[n];
        res[0]={0,1};
        for(auto temp:roads){
            int u=temp[0];
            int v=temp[1];
            int wt=temp[2];
            adjlist[u].push_back({v,wt});
            adjlist[v].push_back({u,wt});
        }
        while(!pq.empty()){
            auto [dist,node]=pq.top();
            pq.pop();
            for(auto it:adjlist[node]){
                int adjnode=it.first;
                long long wt=it.second;
                if(res[adjnode].first>dist+wt){
                    res[adjnode].second=res[node].second%mod;
                    res[adjnode].first=dist+wt;
                    pq.push({res[adjnode].first,adjnode});
                }
                else if(res[adjnode].first==dist+wt){
                    res[adjnode].second=(res[adjnode].second+res[node].second)%mod;
                } 
            }
        }
        return res[n-1].second%mod;
    }
};