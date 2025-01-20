class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<int>rows(row,col),cols(col,row);
        unordered_map<int,pair<int,int>>row_col;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                row_col[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
           auto it=row_col[arr[i]];
           rows[it.first]--;
           cols[it.second]--;
           if(rows[it.first]==0 || cols[it.second]==0){
            return i;
           }
        }
        return 0;
    }
};