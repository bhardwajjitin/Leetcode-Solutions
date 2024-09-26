class Solution {
public:
    bool checkForWord(vector<vector<char>>&board,int row , int col, vector<vector<int>>&visited,string&word,int ind){
      vector<int>di={-1,0,0,1};
      vector<int>dj={0,-1,1,0};
        if(ind==word.size()-1)return true;
        for(int i=0;i<4;i++){
            int nrow=row+di[i];
            int ncol=col+dj[i];

            if(ind<word.size() && nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size()&& board[nrow][ncol]==word[ind+1] && !visited[nrow][ncol]){
                visited[nrow][ncol]=1; 
               if(checkForWord(board,nrow,ncol,visited,word,ind+1))return true;
                visited[nrow][ncol] = 0;
            }
        }
      return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        queue<tuple<int,int>>q;
        int m=board.size();
        int n=board[0].size();
        for(int row = 0 ; row < board.size() ; row++){
            for(int column = 0 ; column < board[0].size() ; column++){
                if(word[0] == board[row][column])q.push({row,column});
            }
        }

        while(!q.empty()){
            vector<vector<int>>visited(m,vector<int>(n,0));
            auto [row,column] = q.front();
            q.pop();
            visited[row][column] = 1;
            bool isPresent = checkForWord(board,row,column,visited,word,0);
            if(isPresent)return true;
        }

        return false;
    }
};