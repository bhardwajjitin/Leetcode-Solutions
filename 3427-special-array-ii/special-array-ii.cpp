class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        if(nums.size()==1){
            vector<bool>temp(queries.size(),true);
            return temp;
        }
        vector<int>res;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2==nums[i-1]%2){
                res.push_back(i);
            }
            else{
                continue;
            }
        }
        vector<bool>ans;
        for(auto it:queries){
            int first=it[0];
            int second=it[1];
            int low=0;
            int high=res.size()-1;
            int ind=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(res[mid]>=first+1){
                    ind=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            if(ind!=-1 && res[ind]<=second){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};