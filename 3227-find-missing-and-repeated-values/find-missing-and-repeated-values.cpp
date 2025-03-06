class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>arr(2500,0),ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(arr[grid[i][j]-1]==0){
                    arr[grid[i][j]-1]=1;
                }
                else if(arr[grid[i][j]-1]==1){
                    arr[grid[i][j]-1]=2;
                    ans.push_back(grid[i][j]);
                }
            }
        }
        for(int i=0;i<2500;i++){
            if(arr[i]==0){
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};