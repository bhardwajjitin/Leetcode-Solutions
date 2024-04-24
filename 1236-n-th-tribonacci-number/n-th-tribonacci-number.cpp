class Solution {
public:
    int tribonacci(int n) {
        long long a=0;
        long long b=1;
        long long c=1;
        if(n==0 || n==1)return n;
        if(n==2)return 1;
        long long d;
        for(int i=3;i<=n;i++){
          d=a+b+c;
          a=b;
          b=c;
          c=d;
        }
        return d;
    }
};