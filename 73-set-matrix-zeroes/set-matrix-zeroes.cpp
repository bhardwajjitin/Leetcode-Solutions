class Solution {
  private:
  void set(vector<vector<int>>&temp,int row,int col,int m,int n){
    // setting up row to zero
    for(int i=0;i<n;i++){
      temp[row][i]=0;
    }
    // setting up col to zero
    for(int i=0;i<m;i++){
      temp[i][col]=0;
    }
  }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        // brute force with extra space 

        // vector<vector<int>>temp=matrix;
        // for(int i=0;i<m;i++){
        //   for(int j=0;j<n;j++){
        //     if(matrix[i][j]==0){
        //        set(temp,i,j,m,n);
        //     }
        //   }
        // }
        // matrix=temp;

        // better approach
        vector<int>row(m,0),col(n,0);
        for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
              row[i]=1;
              col[j]=1;
            }
          }
        }
        for(int i=0;i<row.size();i++){
          if(row[i]==1){
              for(int j=0;j<n;j++){
                 matrix[i][j]=0;
              }
          }
        }
        for(int j=0;j<col.size();j++){
          if(col[j]==1){
            for(int i=0;i<m;i++){
              matrix[i][j]=0;
            }
          }
        }
    }
};