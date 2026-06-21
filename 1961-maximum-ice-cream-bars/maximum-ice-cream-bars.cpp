class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      int max_ele = INT_MIN;
        for (int i = 0; i < costs.size(); i++) {
            max_ele = max(max_ele, costs[i]);
        }

        vector<int> arr(max_ele + 1, 0);
        for (int i = 0; i < costs.size(); i++) {
            arr[costs[i]]++;   
        }

        vector<int> pre(arr.size());
        pre[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            pre[i] = arr[i] + pre[i - 1];
        }

        vector<int> sortedCosts(costs.size());
        for (int i = costs.size() - 1; i >= 0; i--) {
            int val = costs[i];
            sortedCosts[pre[val] - 1] = val; 
            pre[val]--;                   
        }

        int count=0;
        for(int i=0;i<sortedCosts.size();i++){
            if(coins-sortedCosts[i]>=0){
                count++;
                coins-=sortedCosts[i];
            }
        }
        return count;
    }
};