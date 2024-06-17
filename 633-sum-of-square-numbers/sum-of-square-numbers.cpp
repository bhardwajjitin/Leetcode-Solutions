class Solution {
  private:
  bool check(long long a){
    long long low=0;
    long long high=a;
    long long ans=-1;
    while(low<=high){
      long long mid=(low+high)>>1;
      if(mid*mid==a)return true;
      else if(mid*mid<a)low=mid+1;
      else{
        high=mid-1;
      }
    }
    return ans==-1?false:true;
  }
public:
    bool judgeSquareSum(int c) {
        
        for(long long i=0;i*i<=c;i++){
          long long a=c-(i*i);
          if(check(a))return true;
        }
        return false;
    }
};