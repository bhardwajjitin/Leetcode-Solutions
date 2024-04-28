class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long sum=0;
        int m=grid.size();
        int n=grid[0].size();
        map<int,long long>mpr;
        map<int,long long>mpc;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                   mpr[i]++;
                }
            }
        }
       
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==1){
                   mpc[i]++;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int cnt1=0;
                int cnt2=0;
                if(grid[i][j]==1){
                    if(mpr[i]!=0 && mpc[j]!=0){
                   int cnt1=mpr[i]-1;
                   int cnt2=mpc[j]-1;
                   sum+=cnt1*cnt2;
                    }
                }
            }
        }
        return sum;
    }
};