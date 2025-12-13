class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        priority_queue<tuple<int,int,int>>pq;
        int size=technique1.size();
        long long ans=0;
        vector<bool>vis(size,false);
        for(int i=0;i<size;i++){
            int diff=abs(technique1[i]-technique2[i]);
            if(technique1[i]<technique2[i]){
                pq.push({diff,technique2[i],i});
            }
        }
        int need=size-k;
        while(need-- && !pq.empty()){
            auto front=pq.top();
            ans+=get<1>(front);
            vis[get<2>(front)]=true;
            pq.pop();
        }
        for(int i=0;i<size;i++){
            if(!vis[i]){
                ans+=technique1[i];
            }
        }
        return ans;
    }
};