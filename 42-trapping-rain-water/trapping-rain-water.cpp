class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prev(n);
        vector<int>suff(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                prev[i]=INT_MIN;
                st.push(height[i]);
            }
            else if(st.top()<=height[i]){
                 prev[i]=INT_MIN;
                while(!st.empty() && st.top()<=height[i]){
                     st.pop();
                 }
                 st.push(height[i]);
            }
            else{
                prev[i]=st.top();
            }
        }
        stack<int>st1;
        for(int i=n-1;i>=0;i--){
            if(st1.empty()){
                suff[i]=INT_MIN;
                st1.push(height[i]);
            }
            else if(st1.top()<=height[i]){
                 suff[i]=INT_MIN;
                 while(!st1.empty() && st1.top()<=height[i]){
                     st1.pop();
                 }
                 st1.push(height[i]);
            }
            else{
                suff[i]=st1.top();
            }
        }
        int ans=0;
      for(int i=0;i<n;i++){
        if(prev[i]!=INT_MIN && suff[i]!=INT_MIN){
            ans+=min(prev[i],suff[i])-height[i];
        }
      }
      return ans;
    }
};