class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int stcol=INT_MAX;
        int strow=-1;
        int endrow=-1;
        int endcol=INT_MIN;
        bool stflag=false,endflag=false;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1 && !stflag){
                    strow=i;
                    stflag=true;
                }
                if(grid[i][j]==1)
                stcol=min(stcol,j);
            }
        }
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[i].size()-1;j>=0;j--){
                if(grid[i][j]==1 && !endflag){
                    endrow=i;
                    endflag=true;
                }
                if(grid[i][j]==1)
                endcol=max(endcol,j);
            }
        }
        return (endcol-stcol+1)*(endrow-strow+1);
    }
};