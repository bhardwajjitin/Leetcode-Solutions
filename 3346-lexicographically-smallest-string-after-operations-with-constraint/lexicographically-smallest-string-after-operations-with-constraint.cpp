

class Solution {
public:
    string getSmallestString(string s, int k) {
        string ans;
        
        int i = 0;
        int j = 0;
        while (i < s.length() && k > 0) {
            int d = min(s[i] - 'a', 'z' - s[i] + 1);
            if (k >= d) {
                ans += 'a';
                k -= d;
                i++;
                j = i;
            } else {
                char c = s[i] - k;
                k = 0;
                ans += c;
                i++;
                j = i;
            }
        }
        
        string remaining = s.substr(j);
        
        return ans + remaining;
    }
};
