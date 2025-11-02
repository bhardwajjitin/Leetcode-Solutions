class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long max_sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i]=(-1)*nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        
        int j=nums.size()-1;
        int i=0;
        while(i<j){
            max_sum+=(long long)pow(nums[j],2)-(long long)pow(nums[i],2);
            i++;
            j--;
        }
        if(i==j){
        max_sum+=(long long)pow(nums[j],2);
        }
        return max_sum;
    }
};