class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int answer=nums[0];
        int currsum=nums[0];
        for(int index=1;index<nums.size();index++){
            if(nums[index]>nums[index-1]){
                currsum+=nums[index];
            }
            else{
                currsum=nums[index];
            }
            answer=max(answer,currsum);
        }
        return answer;
    }
};