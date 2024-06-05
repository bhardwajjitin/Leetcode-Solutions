class Solution {
  private:
  int solve(int a,int b){
    int ans=0;
    int cnt=0;
    for(int i=0;i<31;i++){
          if((a&(1<<i)) && (b&(1<<i))){
            if(cnt==1){
              ans|=(1<<i);
            }
            cnt=1;
          }
          else if((a&(1<<i))!=(b&(1<<i))){
            if(cnt==0){
              ans|=(1<<i);
            }
          }
          else{
             if(cnt==1){
              ans|=(1<<i);
             }
             cnt=0;
          }
        }
    return ans;
  }
public:
    int getSum(int a, int b) {
        int cnt=0;
        int first=abs(a);
        int second=abs(b);
        bool sign=true;
        if(a<0 && b<0){
        sign=false; 
        }
        if(a>=0 && b<0){
          int ans=solve(a,b);
          if(a<second){
          ans|=(1<<31);
          }
          return ans;
        }
        if(a<0 && b>=0){
          int ans=solve(a,b);
          if(b<first){
          ans|=(1<<31);
          }
          return ans;
        }
        return sign?solve(first,second):(-1)*solve(first,second);
    }
};