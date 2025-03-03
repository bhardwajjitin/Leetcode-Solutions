class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cntless=0;
        vector<int>arr(nums.size());
        int cntequal=0;
        for(auto it:nums){
            if(it==pivot){
               cntequal++;
            }
            else if(it<pivot)
                {
                    cntless++;
                }
        }
        int start=0,end=cntless+cntequal;

        for(auto it:nums){
            if(it<pivot){
                arr[start++]=it;
            }
            else if(it>pivot){
                arr[end++]=it;
            }
            else{
               arr[cntless++]=it;
            }
        }
        return arr;
    }
};