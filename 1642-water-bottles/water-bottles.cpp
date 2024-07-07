class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int q=numBottles/numExchange;
        int r=numBottles%numExchange;
        int sum=numBottles;
        while((q+r)>=numExchange){
          sum+=q;
          int temp=q+r;
          q=temp/numExchange;
          r=temp%numExchange;
        }
        sum+=q;
        return sum;
    }
};