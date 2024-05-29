class Solution {
public:
    int numSteps(string s) {
        string temp=s;
        int n=s.size();
        int cnt=0;
        int i=0;
        int cntone=0;
        while(i<n){
          if(temp[i]=='1')cntone++;
          i++;
        }
        if(cntone==1 && temp[n-1]=='1')return cnt;

        while(true){
          int m=temp.size();
          if(temp[m-1]=='0'){
            for(int i=m-1;i>=1;i--){
              temp[i]=temp[i-1];
            }
            temp[0]='0';
          }
          else{
            int flag=-1;
            for(int i=m-1;i>=0;i--){
              if(temp[i]=='0'){
                temp[i]='1';
                flag=i;
                break;
              }
            }
            if(flag==-1){
              for(int i=0;i<m;i++)temp[i]='0';
              temp.insert(temp.begin()+0,'1');
            }
            else{
              for(int i=flag+1;i<m;i++){
                temp[i]='0';
              }
            }
          }
          cnt++;
          int i=0;
          int cntone=0;
          while(i<m){
            if(temp[i]=='1')cntone++;
            i++;
          }
          if(cntone==1 && temp[m-1]=='1')break;
        }
        return cnt;
    }
};