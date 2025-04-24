class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long answer=0;
        for(int i=0;i<nums.size();i++){
            int low=lower-nums[i];
            int high=upper-nums[i];
            int l=i+1,h=nums.size()-1;
            int stind=-1,endind=-1;
            
            while(l<=h){
                int mid=l+(h-l)/2;
                if(nums[mid]>=low){
                    stind=mid;
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            l=i+1,h=nums.size()-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(nums[mid]<=high){
                    endind=mid;
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
            if(stind!=-1 && endind!=-1){
                answer+=endind-stind+1;
            }     
        }
        return answer;
    }
};