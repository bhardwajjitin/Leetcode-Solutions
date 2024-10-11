class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<pair<int,int>>st;
        for(int i=0;i<nums.size();i++){
            if(st.empty()){
                st.push({nums[i],i});
            }
            else if(st.top().first>=nums[i]){
                st.push({nums[i],i});
            }
        }
        int maxsize=0;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && st.top().first<=nums[i]){
                int size=i-st.top().second;
                maxsize=max(maxsize,size);
                st.pop();
            }
        }
        return maxsize;
    }
};