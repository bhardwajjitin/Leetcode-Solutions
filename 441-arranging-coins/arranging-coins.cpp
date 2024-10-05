class Solution {
public:
    int arrangeCoins(int n) {
       vector<long long>prefix(1e5);
       if(n==1)return 1;
       prefix[0]=1;
       for(long long i=2;i<1e5;i++){
        prefix[i-1]=prefix[i-2]+i;
       }
       int ind=upper_bound(prefix.begin(),prefix.end(),n)-prefix.begin();
       return ind;
    }
};