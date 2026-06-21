class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long max_ele = *max_element(nums.begin(), nums.end());
        long long min_ele = *min_element(nums.begin(), nums.end());

        return (long long)k * (long long)(max_ele - min_ele);
    }
};