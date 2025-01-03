class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>prefix(nums.size());
        prefix[0]=nums[0];
        for(int index=1;index<nums.size();index++){
            prefix[index]=(long long)nums[index]+prefix[index-1];
        }
        int cnt=0;
        for(int index=0;index<nums.size()-1;index++){
            long long firstsum=prefix[index];
            long long secondsum=prefix[nums.size()-1]-prefix[index];
            if(firstsum>=secondsum)cnt++;
        }
        return cnt;
    }
};