class Solution {
    private:
    bool check(int n){
        if(n==1)return false;
        for(int i=2;i<n;i++){
            if(n%i==0)return false;
        }
        return true;
    }
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int>arr;
        for(int i=1;i<=1000;i++){
            if(check(i)){
                arr.push_back(i);
            }
        }
        for(int index=nums.size()-2;index>=0;index--){
            if(nums[index]<nums[index+1])continue;
            else{
                int lower=lower_bound(arr.begin(),arr.end(),nums[index])-arr.begin();
                int start=0;
                while(start<lower-1 &&(nums[index]-arr[start])>=nums[index+1]){
                    start++;
                }
                if(nums[index]>arr[start])
                nums[index]-=arr[start];
            }
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1])return false;
        }
        return true;
    }
};