class Solution {
    int check(vector<vector<int>>& curr) {
    vector<vector<int>> target = {{1, 2, 3}, {4, 5, 0}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (curr[i][j] != target[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        set<vector<vector<int>>>st;
        st.insert(board);
        int di[]={-1,0,0,1};
        int dj[]={0,-1,1,0};
        priority_queue<pair<int,vector<vector<int>>>,vector<pair<int,vector<vector<int>>>>,greater<pair<int,vector<vector<int>>>>>pq;
        pq.push({0,board});
        while(!pq.empty()){
            vector<vector<int>>curr=pq.top().second;
            int steps=pq.top().first;
            if(check(curr))return steps;
            pq.pop();
            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++){
                    if(curr[i][j]==0){
                        for(int k=0;k<4;k++){
                            int nrow=i+di[k];
                            int ncol=j+dj[k];
                            if(nrow>=0 && ncol<3 && ncol>=0 && nrow<2){
                                curr[i][j]=curr[nrow][ncol];
                                curr[nrow][ncol]=0;
                                if(st.find(curr)==st.end()){
                                    st.insert(curr);
                                    pq.push({steps+1,curr});
                                }
                                curr[nrow][ncol]=curr[i][j];
                                curr[i][j]=0;
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};