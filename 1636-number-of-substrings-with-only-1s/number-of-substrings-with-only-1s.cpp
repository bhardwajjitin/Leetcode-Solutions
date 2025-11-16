class Solution {
public:
    int numSub(string s) {
        int total_sum=0;
        int j=0;
        int curr_sum=0,prev_sum=0;
        long long cnt=0;
        while(j<s.size()){
            if(s[j]=='1'){
                cnt++;
                curr_sum=((cnt*(cnt+1))/2)%1000000007;
                total_sum+=(curr_sum-prev_sum)%1000000007;
                prev_sum=curr_sum;
            }
            else{
                cnt=0;
                prev_sum=0;
            }
            j++;
        }
        return total_sum;
    }
};