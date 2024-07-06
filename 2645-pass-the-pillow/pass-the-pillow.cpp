class Solution {
public:
    int passThePillow(int n, int time) {
        bool forward=true;
        bool reverse=false;
        int i=1;
        while(time--){
          if(forward){
            i++;
          }
          if(reverse){
            i--;
          }
          if(i==n){
            forward=false;
            reverse=true;
          }
          if(i==1){
            forward=true;
            reverse=false;
          }
        }
        return i;
    }
};