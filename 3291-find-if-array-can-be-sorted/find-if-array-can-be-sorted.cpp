class Solution {
    int countsetbits(int number){
        int cnt=0;
        while(number){
            cnt+=number&1;
            number>>=1;
        }
        return cnt;
    }
public:
    bool canSortArray(vector<int>& nums) {
        for (int times = 0; times < nums.size(); times++) {
            int i = 0;
            int j = 1;
            while (j < nums.size()-times) {
                if (nums[i] > nums[j]) {
                    if(countsetbits(nums[i]) == countsetbits(nums[j]))
                    swap(nums[i], nums[j]);
                    else
                    return false;
                }
                i++;
                j++;
            }
        }
        return true;
    }
};