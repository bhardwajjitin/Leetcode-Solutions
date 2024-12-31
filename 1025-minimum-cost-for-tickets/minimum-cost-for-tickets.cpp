class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        vector<int>dp(days[n-1]+1,INT_MAX);
        dp[0]=0;
        int k=0;
        for(int i=1;i<=days[n-1];i++){
            while(i<days[k]){
                dp[i]=dp[i-1];
                i++;
            }
            int minone=cost[0]+dp[i-1];
            int minseven=i-7<0?cost[1]:cost[1]+dp[i-7];
            int minthirty=i-30<0?cost[2]:cost[2]+dp[i-30];
            dp[i]=min({minone,minseven,minthirty});
            k++;
        }
        return dp[days[n-1]];
    }
};