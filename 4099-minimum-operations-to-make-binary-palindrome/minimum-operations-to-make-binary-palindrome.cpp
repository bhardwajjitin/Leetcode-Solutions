class Solution {
    private:
    int getlowvalue(int low,int high,vector<int>&arr,int num){
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>num){
                high=mid-1;
            }
            else{
                low=mid+1;
                ans=mid;
            }
        }
        return arr[ans];
    }
    int gethighvalue(int low,int high,vector<int>&arr,int num){
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<num){
                low=mid+1;
            }
            else{
                high=mid-1;
                ans=mid;
            }
        }
        return arr[ans];
    }
public:
    vector<int> minOperations(vector<int>& nums) {
        vector<int>palindrome_number,ans;
        for(int i=1;i<=5000;i++){
            int left = 31 - __builtin_clz(i);
            int right = 0;
            bool flag=true;
            while (left > right) {
                if (((i >> left) & 1) != ((i >> right) & 1)){
                    flag=false;
                    break;
                }
                left--;
                right++;
            }
            if(flag){
                palindrome_number.push_back(i);
            }
        }

        for(int i=0;i<nums.size();i++){
            int low=0;
            int high=palindrome_number.size()-1;
            int low_val=getlowvalue(low,high,palindrome_number,nums[i]);
            int high_val=gethighvalue(low,high,palindrome_number,nums[i]);
            int mini=min(abs(nums[i]-low_val),abs(nums[i]-high_val));
            ans.push_back(mini);
        }
        return ans;
    }
};