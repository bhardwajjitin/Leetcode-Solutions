class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
        sort(hap.begin(),hap.end());
        long long sum=0;
        int n=hap.size()-1;
        int time=0;
        while(k!=0){
              if(hap[n]-time>=0){
             sum+=hap[n]-time;
              }
             n--;
             k--;
             time++;
        }
        return sum;
    }
};