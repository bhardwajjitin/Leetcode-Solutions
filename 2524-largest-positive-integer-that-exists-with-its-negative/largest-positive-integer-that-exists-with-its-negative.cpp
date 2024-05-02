// class Solution {
// public:
//     int findMaxK(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int i=0;
//         int j=nums.size()-1;
//         while(i!=j){
//           int temp=(-1)*nums[i];
//           if(temp==nums[j]){
//             return nums[j];
//           }
//           else if(temp>nums[j]){
//             i++;
//           }
//           else{
//             j--;
//           }
//         }
//         return -1;
//     }
// };
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size(), ans = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int alter = nums[i] - (2 * nums[i]);
            if (mp.find(alter) != mp.end())
                ans = max(ans, abs(alter));
            mp[nums[i]]++;
        }
        return ans;
    }
};