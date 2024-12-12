class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        map<int,int>umap;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        for(int i=0;i<n;i++){
            pq.push({0,i});
        }
        vector<int>empty;
        for(auto it:meetings){
            long long start=it[0];
            long long end=it[1];
            while(!pq.empty() && pq.top().first<=start){
                int room=pq.top().second;
                pq.pop();
                empty.push_back(room);
            }
            for(auto it:empty){
                pq.push({0,it});
            }
            empty.clear();
            long long newtime=pq.top().first==0?end:pq.top().first+(end-start);
            int room=pq.top().second;
            umap[room]++;
            pq.pop();
            pq.push({newtime,room});
        }
        int ans=0,maxi=INT_MIN;
        for(auto it:umap){
            if(it.second>maxi){
                ans=it.first;
                maxi=it.second;
            }
        }
        return ans;
    }
};