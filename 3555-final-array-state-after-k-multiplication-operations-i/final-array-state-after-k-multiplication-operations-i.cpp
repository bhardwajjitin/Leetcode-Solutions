class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(k--){
            int topval=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            topval*=multiplier;
            pq.push({topval,index});
        }
        vector<int>answer(nums.size());
        while(!pq.empty()){
            int ind=pq.top().second;
            int val=pq.top().first;
            pq.pop();
            answer[ind]=val;
        }
        return answer;
    }
};