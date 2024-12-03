class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res="";
        unordered_set<int>st(spaces.begin(),spaces.end());
        for(int i=0;i<s.size();i++){
            if(st.find(i)!=st.end()){
                res+=" ";
            }
            res+=s[i];
        }
        return res;
    }
};