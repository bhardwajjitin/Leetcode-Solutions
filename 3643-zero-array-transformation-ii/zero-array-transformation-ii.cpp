class Solution {
    private:
    bool ispossible(vector<vector<int>>&queries,vector<int>&nums,int ind){
        unordered_map<int,int>umap;
        for(int i=0;i<ind;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            int val=queries[i][2];
            umap[start]-=val;
            umap[end+1]+=val;
        }
        if(nums[0]>abs(umap[0])){
            return false;
        }
        for(int i=1;i<nums.size();i++){
            umap[i]=umap[i-1]+umap[i];
            if(nums[i]>abs(umap[i]))return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    bool flag=false;
    for(auto it:nums){
      if(it!=0)flag=true;
    }
    if(!flag)return 0;
    int k=-1;
    int low=1;
    int high=queries.size();
    while(low<=high){
        int mid=low+(high-low)/2;
        if(ispossible(queries,nums,mid)){
            k=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return k;
    }
};