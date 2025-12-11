class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int total=0;
        unordered_map<int,long long>right_side;
        unordered_map<int,long long>left_side;
        for(int i=nums.size()-1;i>=2;i--){
            right_side[nums[i]]++;
        }
        left_side[nums[0]]++;
        for(int i=1;i<nums.size()-1;i++){
            int curr_value=nums[i]*2;
            long long on_left=left_side[curr_value];
            long long on_right=right_side[curr_value];
            total = ( total + (1LL * on_left * on_right ) % 1000000007 ) % 1000000007;
            left_side[nums[i]]++;
            right_side[nums[i+1]]--;
            if(right_side[nums[i+1]]==0){
                right_side.erase(nums[i+1]);
            }
        }
        return total;
    }
};