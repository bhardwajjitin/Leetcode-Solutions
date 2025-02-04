class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ascending=1;
        int descending=1;
        int answer=1;
        for(int index=1;index<nums.size();index++){
            if(nums[index]>nums[index-1]){
                ascending+=1;
                descending=1;
            }
            else if(nums[index]<nums[index-1]){
                ascending=1;
                descending+=1;
            }
            else{
                ascending=1;
                descending=1;
            }
            answer=max(answer,max(ascending,descending));
        }
        return answer;
    }
};