class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])count++;
           if(count>2){
            while(i<nums.size() && nums[i]==nums[i-1]){
                nums.erase(nums.begin()+i);
            }
           }
        if(nums[i]!=nums[i-1])count=1;
        }
        return nums.size();
    }
};