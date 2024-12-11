class Solution {
    private:
    int blackbox(vector<int>&res,int val){
        int low=0;
        int high=res.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(res[mid]<=val){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int whitebox(vector<int>&res,int val){
        int low=0;
        int high=res.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(res[mid]>=val){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int>lower_limit,upper_limit;
        for(int i=0;i<nums.size();i++){
            int lower=nums[i]-k;
            int higher=nums[i]+k;
            lower_limit.push_back(lower);
            upper_limit.push_back(higher);
        }
        int maxi=0;
        int low=lower_limit[0];
        int high=upper_limit[upper_limit.size()-1];
        for(int i=low;i<=high;i++){
            int getlowind=blackbox(lower_limit,i);
            int gethighind=whitebox(upper_limit,i);
            if(getlowind>=gethighind){
                int temp=getlowind-gethighind+1;
                maxi=max(maxi,temp);
            }
        }
        return maxi;
    }
};