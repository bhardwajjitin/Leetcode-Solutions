class Solution {
private:
    int solve(int curr, int day, int k, int n, vector<vector<int>>& stay,
              vector<vector<int>>& travel) {
        if (day >= k)
            return 0;

        int stayhere =
            stay[day][curr] + solve(curr, day + 1, k, n, stay, travel);
        int travelfrom = 0;
        for (int dest = 0; dest < n; dest++) {
            int temp =
                travel[curr][dest] + solve(dest, day + 1, k, n, stay, travel);
            travelfrom = max(travelfrom, temp);
        }
        return max(stayhere, travelfrom);
    }

public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore,
                 vector<vector<int>>& travelScore) {
        int maxi = 0;
        // for(int city=0;city<n;city++){
        //     maxi=max(maxi,solve(city,0,k,n,stayScore,travelScore));
        // }
        // return maxi;
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));
        for (int day = k - 1; day >= 0; day--) {
            for (int city = 0; city < n; city++) {
                int stayhere = stayScore[day][city] + dp[city][day + 1];
                int travelfrom = 0;
                for (int dest = 0; dest < n; dest++) {
                    int temp = travelScore[city][dest] + dp[dest][day + 1];
                    travelfrom = max(travelfrom, temp);
                }
                dp[city][day] = max(stayhere, travelfrom);
            }
        }
        for (int city = 0; city < n; city++) {
            maxi = max(maxi, dp[city][0]);
        }
        return maxi;
    }
};