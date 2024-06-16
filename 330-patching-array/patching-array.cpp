class Solution {
public:
    int minPatches(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        long long int max_sum = 0;
        int ans=0;
        for(int i = 0 ; i < coins.size() ; i++){
            if(max_sum>=target){
                return ans;
            }
            while(max_sum+1<coins[i]){
                ans++;
                max_sum=max_sum+max_sum+1;
                if(max_sum>=target){
                return ans;
            }
            }
            if(max_sum+1>=coins[i]){
                max_sum+=coins[i];
            }
        }
        while(max_sum<target){
            ans++;
            max_sum=max_sum+max_sum+1;
        }
        return ans;
    }
};