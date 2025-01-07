class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push("(");
            }
            else{
                int sum=0;
                while(!st.empty() && st.top()!="("){
                    int num=stoi(st.top());
                    sum+=num;
                    st.pop();
                }
                st.pop();
                if(sum!=0){
                sum*=2;
                string newchar=to_string(sum);
                st.push(newchar);
                }
                else{
                    st.push("1");
                }
            }
        }
        int ans=0;
        while(!st.empty()){
            int num=stoi(st.top());
            ans+=num;
            st.pop();
        }
        return ans;
    }
};