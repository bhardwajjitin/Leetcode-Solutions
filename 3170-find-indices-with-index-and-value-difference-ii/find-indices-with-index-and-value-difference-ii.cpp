class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n=nums.size();
        vector<pair<int,int>>res(n);
        res[n-1]={n-1,n-1};
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[res[i+1].second]){
                res[i].second=i;
            }
            else if(nums[i]<=nums[res[i+1].second]){
                res[i].second=res[i+1].second;
            }
            if(nums[i]<nums[res[i+1].first]){
                res[i].first=i;
            }
            else if(nums[i]>=nums[res[i+1].first]){
                res[i].first=res[i+1].first;
            }
        }
        for(int i=0;i<n-indexDifference;i++){
            int next_index=i+indexDifference;
            if(abs(nums[res[next_index].first]-nums[i])>=valueDifference){
                return {res[next_index].first,i};
            }
            if(abs(nums[res[next_index].second]-nums[i])>=valueDifference){
                return {res[next_index].second,i};
            }
        }
        return {-1,-1};
    }
};