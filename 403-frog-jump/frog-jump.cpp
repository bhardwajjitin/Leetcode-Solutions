class Solution {
private:
    int search_index(vector<int>& stones, int dist) {
        int low = 0, high = stones.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (stones[mid] == dist) return mid;
            else if (stones[mid] > dist) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }

    bool solve(vector<int>& stones, int index, int curr_k, vector<vector<int>>& dp) {
        if (index == stones.size() - 1) return true;

        if (dp[index][curr_k] != -1) return dp[index][curr_k];

        for (int jump = curr_k - 1; jump <= curr_k + 1; jump++) {
            if (jump <= 0) continue;

            int next_dist = stones[index] + jump;
            int next_index = search_index(stones, next_dist);

            if (next_index != -1) {
                if (solve(stones, next_index, jump, dp)) {
                    return dp[index][curr_k] = true;
                }
            }
        }

        return dp[index][curr_k] = false;
    }

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (stones[1] - stones[0] > 1) return false;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(stones, 1, 1, dp);
    }
};