class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i=0;
        int j=0;
        int cnt=0;
        if(nums[i]!=0){
                while(i<nums.size() && nums[i]==1){
                    i++;
                    j++;
            }
        }
        while(j<nums.size()){
            if(j-i+1<3){
                j++;
            }
            else if(j-i+1==3){
                bool flag=false;
                for(int k=i;k<=j;k++){
                    if(nums[k]==0)flag=true;
                    nums[k]=!nums[k];
                }
                if(flag)cnt++;
                if(nums[i]!=0){
                while(i<nums.size() && nums[i]==1){
                    i++;
                    j++;
                }
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        for(auto it:nums)if(it==0)return -1;
        return cnt;
    }
};