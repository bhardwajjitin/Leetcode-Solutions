class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        map<int,vector<pair<int,double>>>mp;
        map<int,int>mp1;
        for(int i=0;i<bombs.size();i++){
            int x1=bombs[i][0];
            int y1=bombs[i][1];
            int r1=bombs[i][2];
            mp1[i]=r1;
            for(int j=i+1;j<bombs.size();j++){
                int x2=bombs[j][0];
                int y2=bombs[j][1];
                double dis=sqrt(pow(abs(x2-x1),2)+pow(abs(y2-y1),2));
                mp[i].push_back({j,dis});
                mp[j].push_back({i,dis});
            }
        }
         
        int maxi=0;
        for(int i=0;i<bombs.size();i++){
            double r=bombs[i][2];
            int cnt=0;
            vector<int>vis(bombs.size(),0);
            queue<pair<int,double>>q;
            q.push({i,r});
            cnt++;
            vis[i]=1;
            while(!q.empty()){
                int node=q.front().first;
                double radi=q.front().second;
                q.pop();
                maxi=max(maxi,cnt);
                for(auto it:mp[node]){
                    int temp=it.first;
                    double dis=it.second;
                    if(radi>=dis && !vis[temp]){
                        vis[temp]=1;
                        q.push({temp,mp1[temp]});
                        cnt++;
                    }
                }
            }
        }
        return maxi;
    }
};