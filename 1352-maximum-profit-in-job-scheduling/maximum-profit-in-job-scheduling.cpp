class Solution {
private:
    int getind(vector<tuple<int,int,int>>&res,int val,int low){
        int high = res.size() - 1, nextJob = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (get<0>(res[mid]) >= val) {
                nextJob = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return nextJob;
    }
    int solve(int ind, vector<tuple<int, int, int>>& res, vector<int>& dp) {
        if (ind >= res.size())
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int notpick = solve(ind + 1, res, dp);
        int pick = get<2>(res[ind]);
        int nextJob=getind(res,get<1>(res[ind]),ind+1);
        if (nextJob != -1) {
             pick+=solve(nextJob, res, dp);
        }
        return dp[ind] = max(pick, notpick);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        vector<tuple<int, int, int>> res;
        for (int i = 0; i < startTime.size(); i++) {
            int start = startTime[i];
            int end = endTime[i];
            int pro = profit[i];
            res.push_back({start, end, pro});
        }
        sort(res.begin(), res.end());
        vector<int> dp(startTime.size(), -1);
       return solve(0,res,dp);
    }
};