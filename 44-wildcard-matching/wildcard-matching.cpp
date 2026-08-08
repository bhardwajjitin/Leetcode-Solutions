class Solution {
private:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp) {

        if (j < 0) {
            return i < 0;
        }

        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
        }

        if (p[j] == '*') {
            return dp[i][j] = solve(s, p, i - 1, j, dp) ||
                              solve(s, p, i, j - 1, dp);
        }

        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(
            s.size(), 
            vector<int>(p.size(), -1)
        );

        return solve(s, p, s.size() - 1, p.size() - 1, dp);
    }
};