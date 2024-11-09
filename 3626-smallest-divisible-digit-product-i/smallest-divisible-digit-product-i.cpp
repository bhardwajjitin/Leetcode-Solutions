class Solution {
    private:
    int getsum(int n){
        int pro=1;
        while(n!=0){
            int r=n%10;
            pro*=r;
            n/=10;
        }
        return pro;
    }
public:
    int smallestNumber(int n, int t) {
        while(true){
            int temp=getsum(n);
            if(temp%t==0)return n;
            n++;
        }
        return -1;
    }
};