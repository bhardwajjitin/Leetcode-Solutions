class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        vector<long long>prefix(n+1);
        prefix[0]=0;
        for(int i=1;i<=shifts.size();i++){
            prefix[i]=prefix[i-1]+shifts[i-1];
        }
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            long long need=prefix[n]-prefix[i];
            s[i]=(ch-'a'+need) % 26 + 'a';
        }
        return s;
    }
};