class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int cnt=0;
        for(int i=0;i<nums.size();i++){  
            if(nums[i]==0){
                st.push(nums[i]);
                continue;
            }
            if(!st.empty() && nums[i]==st.top()){
                st.push(nums[i]);
            }
            while(!st.empty() && nums[i]<st.top()){
                st.pop();
            }
            if(st.empty() || st.top()<nums[i]){
                st.push(nums[i]);
                cnt++;
            }
        }
        return cnt;
    }
};