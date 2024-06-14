class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod=1e9+7;
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        while(k--){
          int top=pq.top();
          pq.pop();
          pq.push(top+1);
        }
        long long sum=1;
        while(!pq.empty()){
          sum=(sum*pq.top())%mod;
          pq.pop();
        }
        return sum;
    }
};