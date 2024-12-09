class Solution {
private:
    int solve(int ind, vector<vector<int>>& events, int k,vector<vector<int>>&dp) {
        if (k >= 2 || ind >= events.size())
            return 0;

        if(dp[ind][k]!=-1)return dp[ind][k];

        int notpick = solve(ind + 1, events, k,dp);
        int pick = events[ind][2];
        int low = ind + 1, high = events.size() - 1, nextEvent = events.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > events[ind][1]) {
                nextEvent = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (nextEvent < events.size()) {
            pick += solve(nextEvent, events, k + 1,dp);
        }
        return dp[ind][k]=max(pick, notpick);
    }

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<vector<int>>dp(events.size(),vector<int>(3,-1));
        return solve(0, events, 0,dp);
    }
};