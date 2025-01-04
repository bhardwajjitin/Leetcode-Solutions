class Solution {
    private:
    int helper(int i,int j,string&s){
        set<char>myst;
        for(int k=i;k<=j;k++){
            myst.insert(s[k]);
        }
        return myst.size();
    }
public:
    int countPalindromicSubsequence(string s) {
        set<char>st;
        int i=0,j=s.size()-1;
        int cnt=0;
        while(i+2<=j){
            if(st.find(s[i])==st.end()){
            char ch=s[i];
            while(i+2<=j && s[j]!=ch){
                j--;
            }
            if(s[j]==ch){
            int totaldistinct=helper(i+1,j-1,s);
            cnt+=totaldistinct;
            st.insert(ch);
            }
            j=s.size()-1;
            }
            i++;
        }
        return cnt;
    }
};