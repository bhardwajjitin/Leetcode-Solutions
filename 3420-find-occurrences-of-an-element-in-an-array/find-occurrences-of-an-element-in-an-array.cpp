class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int cnt=0;
        for(auto it:nums)if(it==x)cnt++;
        vector<int>occ(cnt);
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                occ[j]=i;
                j++;
            }
        }
        vector<int>ans;
        for(auto it:queries){
            if(it>cnt)ans.push_back(-1);
            else{
                ans.push_back(occ[it-1]);
            }
        }
        return ans;
    }
};