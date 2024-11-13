class Solution {
    private:
    int getlower(vector<int>&nums,int&anslow,int low,int l){
        int h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]>=low){
                anslow=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return anslow;
    }
    int gethigher(vector<int>&nums,int&ansup,int high,int l){
        int h=nums.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]<=high){
                ansup=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ansup;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
            int low=lower-nums[i];
            int upp=upper-nums[i];
            int anslow=-1;
            int ansup=-1;
            getlower(nums,anslow,low,i+1);
            gethigher(nums,ansup,upp,i+1);
            if(ansup!=-1 && anslow!=-1){
            cnt+=(ansup-anslow)+1;
            }
        }
        return cnt;
    }
};