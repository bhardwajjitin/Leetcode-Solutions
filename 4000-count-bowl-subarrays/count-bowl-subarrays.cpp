class Solution {
    private:
    void solve(vector<int>&nums,vector<bool>&arr,vector<bool>&arr1){
        stack<int>st;
        st.push(nums[nums.size()-1]);
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums[i]){
                st.pop();
            }
            if(!st.empty()){
                arr[i]=true;
            }
            st.push(nums[i]);
        }
        while(!st.empty()) st.pop();
        st.push(nums[0]);
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && st.top()<nums[i]){
                st.pop();
            }
            if(!st.empty()){
                arr1[i]=true;
            }
            st.push(nums[i]);
        }
    }
public:
    long long bowlSubarrays(vector<int>& nums) {
       long long cnt=0;
       vector<bool>arr(nums.size(),false),arr1(nums.size(),false);
       solve(nums,arr,arr1);
       for(int i=1;i<nums.size()-1;i++){
        if(arr[i] && arr1[i]){
            cnt++;
        }
       }
       return cnt;
    }
};