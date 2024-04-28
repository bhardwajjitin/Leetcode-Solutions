class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int di[]={0,1,1};
        int dj[]={-1,-1,0};
        int di1[]={-1,-1,0};
        int dj1[]={-1,0,-1};
        int di2[]={-1,-1,0};
        int dj2[]={0,1,1};
        int di3[]={0,1,1};
        int dj3[]={1,1,0};
        int sum=0,sum1=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int cnt=0,cnt1=0,cnt2=0,cnt3=0;
                for(int k=0;k<3;k++){
                    int nr=i+di[k];
                    int nc=j+dj[k];
                    int nr1=i+di1[k];
                    int nc1=j+dj1[k];
                    int nr2=i+di2[k];
                    int nc2=j+dj2[k];
                    int nr3=i+di3[k];
                    int nc3=j+dj3[k];
                    if(nr>=0 && nr<3 && nc>=0 && nc<3 && grid[nr][nc]=='W'){
                        cnt++;
                    }
                     if(nr1>=0 && nr1<3 && nc1>=0 && nc1<3 && grid[nr1][nc1]=='W'){
                        cnt1++;
                    }
                     if(nr2>=0 && nr2<3 && nc2>=0 && nc2<3 && grid[nr2][nc2]=='W'){
                        cnt2++;
                    }
                     if(nr3>=0 && nr3<3 && nc3>=0 && nc3<3 && grid[nr3][nc3]=='W'){
                        cnt3++;
                    }
                }
                if(cnt>=3 || cnt1>=3 || cnt2>=3 || cnt3>=3)return true;
            }
        }
          for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int cnt=0,cnt1=0,cnt2=0,cnt3=0;
                for(int k=0;k<3;k++){
                    int nr=i+di[k];
                    int nc=j+dj[k];
                    int nr1=i+di1[k];
                    int nc1=j+dj1[k];
                    int nr2=i+di2[k];
                    int nc2=j+dj2[k];
                    int nr3=i+di3[k];
                    int nc3=j+dj3[k];
                    if(nr>=0 && nr<3 && nc>=0 && nc<3 && grid[nr][nc]=='B'){
                        cnt++;
                    }
                     if(nr1>=0 && nr1<3 && nc1>=0 && nc1<3 && grid[nr1][nc1]=='B'){
                        cnt1++;
                    }
                     if(nr2>=0 && nr2<3 && nc2>=0 && nc2<3 && grid[nr2][nc2]=='B'){
                        cnt2++;
                    }
                     if(nr3>=0 && nr3<3 && nc3>=0 && nc3<3 && grid[nr3][nc3]=='B'){
                        cnt3++;
                    }
                }
                if(cnt>=3 || cnt1>=3 || cnt2>=3 || cnt3>=3)return true;
            }
        }
        return false;
    }
};