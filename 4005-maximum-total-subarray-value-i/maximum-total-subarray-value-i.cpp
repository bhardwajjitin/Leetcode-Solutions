class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long answer=0;
        int max_val=INT_MIN,min_val=INT_MAX;
        for(int i=0;i<nums.size();i++){
            max_val=max(max_val,nums[i]);
            min_val=min(min_val,nums[i]);
        }
        answer=(long long)(max_val-min_val)*(long long)k;
        return answer;
    }
};