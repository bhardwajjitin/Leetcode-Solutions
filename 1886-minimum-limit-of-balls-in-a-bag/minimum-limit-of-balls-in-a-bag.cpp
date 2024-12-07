class Solution {
    private:
    int checksize(vector<int>&nums,int mid){
        int cnt=0;
        for(auto it:nums){
            int quot=it/mid;
            int rem=it%mid==0?0:1;
            cnt+=quot+rem;
        }
        return cnt;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int ans=-1;
        int maxsize=nums.size()+maxOperations;
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(checksize(nums,mid)<=maxsize){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};