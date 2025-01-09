class Solution {
    private:
    bool isposs(int mid,vector<tuple<int,int,int>>&arr){
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            int actual=get<1>(arr[i]);
            int req=get<2>(arr[i]);
            if(req<=mid && mid>=actual){
                mid-=actual;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<tuple<int,int,int>>arr;
        int low=0;
        int high=1e9;
        for(auto it:tasks){
            int actual=it[0];
            int mini=it[1];
            int diff=mini-actual;
            arr.push_back({diff,actual,mini});
            low+=actual;
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isposs(mid,arr)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};