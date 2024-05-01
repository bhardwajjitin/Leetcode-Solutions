class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int n=heights.size();
      // brute force

      // int maxi=0;
      //   for(int i=0;i<n;i++){
      //     int mini=heights[i];
      //     for(int j=i;j<n;j++){
      //         mini=min(mini,heights[j]);
      //         int ans=mini*(j-i+1);
      //         maxi=max(ans,maxi);
      //     }
      //   }
      //   return maxi;

      stack<int>st,st1;
      vector<int>pre,suff;
      for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()]>=heights[i]){
          st.pop();
        }
        if(st.empty()){
           pre.push_back(n);
        }
        else{
          pre.push_back(st.top());
        }
        st.push(i);
      }
      for(int i=0;i<n;i++){
        while(!st1.empty() && heights[st1.top()]>=heights[i]){
          st1.pop();
        }
        if(st1.empty()){
          suff.push_back(-1);
        }
        else{
          suff.push_back(st1.top());
        }
        st1.push(i);
      }
      int ans=0;
      reverse(pre.begin(),pre.end());
      for(int i=0;i<n;i++){
         int temp=heights[i]*(pre[i]-suff[i]-1);
         ans=max(ans,temp);
      }
      return ans;
    }
};