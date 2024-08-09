class Solution {
    private:
    bool check(int startrow,int startcol,int endrow,int endcol,vector<vector<int>>&grid){
    set<int>st;
    for(int i=startrow;i<=endrow;i++){
        for(int j=startcol;j<=endcol;j++){
            if(grid[i][j]>9)return false;
            if(grid[i][j]==0)return false;
            if(st.find(grid[i][j])!=st.end())return false;
            st.insert(grid[i][j]);
        }
    }
    int rowsum=grid[startrow][startcol]+grid[startrow][startcol+1]+grid[startrow][startcol+2];
    int colsum=grid[startrow][startcol]+grid[startrow+1][startcol]+grid[startrow+2][startcol];
    int sum=0;
    if(rowsum!=colsum)return false;
    for(int i=startrow+1;i<=endrow;i++){
     sum+=grid[i][startcol]+grid[i][startcol+1]+grid[i][startcol+2];
     if(rowsum!=sum)return false;
     sum=0;
    }
    sum=0;
    for(int i=startcol+1;i<=endcol;i++){
sum=grid[startrow][i]+grid[startrow+1][i]+grid[startrow+2][i];
if(colsum!=sum)return false;
sum=0;
    }
    sum=0;
    int diagsum1=grid[startrow][startcol]+grid[startrow+1][startcol+1]+grid[startrow+2][startcol+2];
    if(diagsum1!=rowsum)return false;
    int diagsum2=grid[startrow][endcol]+grid[startrow+1][endcol-1]+grid[startrow+2][endcol-2];
    if(diagsum2!=rowsum)return false;

    return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int startrow=0;
        int startcol=0;
        int endrow=2;
        int endcol=2;
        int cnt=0;
        while(endrow<row){
            while(endcol<col){
            if(check(startrow,startcol,endrow,endcol,grid)){
                cnt++;
            }
            startcol++;
            endcol++;
            }
            startcol=0;
            endcol=2;
            startrow++;
            endrow++;
        }
        return cnt;
    }
};