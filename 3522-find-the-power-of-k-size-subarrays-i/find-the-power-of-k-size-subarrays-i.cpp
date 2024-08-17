class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        int i=0;
        int j=0;
        while(j<nums.size()){
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                bool flag=false;
                for(int k=i;k<j;k++){
                    if(nums[k+1]!=nums[k]+1){
                        ans.push_back(-1);
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    ans.push_back(nums[j]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};