class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<n;i++){
          int row=0;
          int col=i;
           while(row+1<m && col+1<n){
              if(matrix[row][col]!=matrix[row+1][col+1])return false;
              row++;
              col++;
           }
        }
        for(int i=0;i<m;i++){
          int row=i;
          int col=0;
           while(row+1<m && col+1<n){
              if(matrix[row][col]!=matrix[row+1][col+1])return false;
              row++;
              col++;
           }
        }
        return true;
    }
};