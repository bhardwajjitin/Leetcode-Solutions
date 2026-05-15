class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        long long temp=0;
        int i=0,j=0;
        int size=INT_MIN;
        while(j<nums.size()){
            while(i<j && (temp&nums[j])>0){
                temp^=nums[i];
                i++;
            }
            temp|=nums[j];
            size=max(size,j-i+1);
            j++;
        }
        return size;
    }
};