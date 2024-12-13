class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        long long sum=0;
        while(!pq.empty()){
            if(umap.find(pq.top().second)==umap.end()){
                sum+=pq.top().first;
                umap[pq.top().second]++;
                umap[pq.top().second+1]++;
                umap[pq.top().second-1]++;
            }
            pq.pop();
        }
        return sum;
    }
};