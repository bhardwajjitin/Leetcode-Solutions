class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=friends.size();
        vector<int>vis(n,0);
        queue<pair<int,int>>q;
        q.push({id,0});
        vis[id]=1;
        vector<int>lev;
        while(!q.empty()){
          int node=q.front().first;
          int dis=q.front().second;
          q.pop();
          if(dis==level){
            lev.push_back(node);
          }
          for(auto it:friends[node]){
            if(!vis[it]){
              vis[it]=1;
              q.push({it,dis+1});
            }
          }
        }
        unordered_map<string,int>umap;
        for(int i=0;i<lev.size();i++){
          for(auto it:watchedVideos[lev[i]]){
            umap[it]++;
          }
        }
        vector<string>ans;
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        for(auto it:umap){
          pq.push({it.second,it.first});
        }
        while(!pq.empty()){
          ans.push_back(pq.top().second);
          pq.pop();
        }
        return ans;
    }
};