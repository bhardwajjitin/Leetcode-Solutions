class Solution {
  private:
  bool solve(string&s,string&p,int i,int j){
    if(i<0 && j<0)return true;
    if(i<0 && j>=0){
      stack<char>st;
      for(int k=0;k<=j;k++){
        if((p[k]>='a' && p[k]<='z') || (p[k]=='.')){
          st.push(p[k]);
        }
        else{
          if(!st.empty()){
          st.pop();
          }
        }
      }
      if(st.size()>0)return false;
      return true;
    }
    if(i>=0 && j<0)return false;
    if(s[i]==p[j] || p[j]=='.'){
      return solve(s,p,i-1,j-1);
    }
    if(p[j]=='*'){
       if(s[i]==p[j-1] || p[j-1]=='.'){
        return (solve(s,p,i-1,j)|solve(s,p,i,j-2));
       }
       else{
         return solve(s,p,i,j-2);
       }
    }
    return false;
  }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return solve(s,p,n-1,m-1);
    }
};