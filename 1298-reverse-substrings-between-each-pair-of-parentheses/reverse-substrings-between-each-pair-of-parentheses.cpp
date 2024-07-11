class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        string ans;
        for(auto it:s){
          if(it!=')'){
            st.push(it);
          }
          else{
            ans="";
            while(st.top()!='('){
              ans+=st.top();
              st.pop();
            }
            st.pop();
            for(auto it:ans){
              st.push(it);
            }
          }
        }
        ans="";
        while(!st.empty()){
          ans+=st.top();
          st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};