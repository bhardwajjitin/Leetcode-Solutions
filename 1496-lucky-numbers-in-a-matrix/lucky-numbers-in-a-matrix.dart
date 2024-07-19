class Solution {
  List<int> luckyNumbers (List<List<int>> matrix) {
    int m=matrix.length;
    int n=matrix[0].length;
    List<int>rowmin=List.filled(m,1000001);
    List<int>colmax=List.filled(n,-1);
    List<int>ans=[];
    for(int i=0;i<matrix.length;i++){
      for(int j=0;j<matrix[0].length;j++){
        rowmin[i]=min(rowmin[i],matrix[i][j]);
      }
    }
    for(int j=0;j<matrix[0].length;j++){
        for(int i=0;i<matrix.length;i++){
          colmax[j]=max(colmax[j],matrix[i][j]);
        }
    }
    for(int i=0;i<matrix.length;i++){
      for(int j=0;j<matrix[0].length;j++){
        if(matrix[i][j]==rowmin[i] && matrix[i][j]==colmax[j]){
          ans.add(matrix[i][j]);
        }
      }
    }
    return ans;
  }
}