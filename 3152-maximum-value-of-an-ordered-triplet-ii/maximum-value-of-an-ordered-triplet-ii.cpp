class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       int n=nums.size();
       vector<int>maxvalue(n-2);
       maxvalue[n-3]=nums[n-1];
       for(int i=n-2;i>=2;i--){
        maxvalue[i-2]=max(maxvalue[i-1],nums[i]);
       }
       long long maxi=nums[0];
       long long ans=0;
       for(int i=1;i<n-1;i++){
        long long diff=maxi-nums[i];
        ans=max(ans,diff*maxvalue[i-1]);
        maxi=max(maxi,(long long)nums[i]);
       }
       return ans;
    }
};