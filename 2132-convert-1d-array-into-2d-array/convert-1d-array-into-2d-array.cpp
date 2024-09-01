class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n<original.size() || m*n>original.size())return {};
        vector<vector<int>>arr(m,vector<int>(n));
        int row=0;
        int i=0;
        while(i<original.size()){
            int col=0;
            while(col<n){
                arr[row][col]=original[i++];
                col++;
            }
            row++;
        }
        return arr;
    }
};