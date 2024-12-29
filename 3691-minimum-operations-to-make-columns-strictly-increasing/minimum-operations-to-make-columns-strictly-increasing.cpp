class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int op=0;
        for(int i=0;i<grid[0].size();i++){
            int start=grid[0][i];
            for(int j=1;j<grid.size();j++){
                if(grid[j][i]<=start){
                op+=start+1-grid[j][i];
                grid[j][i]=start+1;
                }
                start=grid[j][i];
            }
        }
        return op;
    }
};