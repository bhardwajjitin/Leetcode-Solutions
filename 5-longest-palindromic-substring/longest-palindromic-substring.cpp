class Solution {
    bool check(string&s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        string ans="";
        int ansL = 0;
        for(int i=0;i<=s.size();i++){
            string temp="";
            for(int j = i ; j < s.size() ; j++){
                temp += s[j];

                if(check(temp)  and ansL < (int)temp.size()){
                    ansL = temp.size();
                    ans = temp;
                }
            }
        }
        return ans;
    }
};