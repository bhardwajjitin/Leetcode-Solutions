class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int temp=blue;
        int temp1=red;
        int i=1;
        bool flag=false;
        int mini=INT_MIN;
        while(true){
          if(!flag){
            if(temp>=i){
              temp-=i;
              flag=true;
              mini=max(mini,i);
            }
            else{
              break;
            }
          }
          else{
            if(temp1>=i){
              temp1-=i;
              flag=false;
              mini=max(mini,i);
            }
            else{
              break;
            }
          }
          i++;
        }
        temp=blue;
        temp1=red;
        flag=false;
        i=1;
        while(true){
          if(!flag){
            if(temp1>=i){
              temp1-=i;
              flag=true;
              mini=max(mini,i);
            }
            else{
              break;
            }
          }
          else{
            if(temp>=i){
              temp-=i;
              flag=false;
              mini=max(mini,i);
            }
            else{
              break;
            }
          }
          i++;
        }
        return mini;
    }
};