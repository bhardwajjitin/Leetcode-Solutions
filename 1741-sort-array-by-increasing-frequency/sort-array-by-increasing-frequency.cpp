class comp{
  public:
  bool operator()(const pair<int,int>&a,const pair<int,int>&b){
    if(a.first==b.first)return a.second<b.second;
    return a.first>b.first;
  }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        unordered_map<int,int>umap;
        for(auto it:nums)umap[it]++;
        for(auto it:umap){
          pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(!pq.empty()){
          int temp=pq.top().first;
          while(temp--){
          ans.push_back(pq.top().second);
          }
          pq.pop();
        }
        return ans;
    }
};