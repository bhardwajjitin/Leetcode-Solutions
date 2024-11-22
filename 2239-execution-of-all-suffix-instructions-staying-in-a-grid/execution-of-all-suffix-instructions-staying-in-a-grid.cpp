class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int row=startPos[0];
        int col=startPos[1];
        vector<int>ans(s.size());
        for(int i=0;i<s.size();i++){
            int j=i;
            int cnt=0;
            queue<pair<int,int>>q;
            q.push({row,col});
            while(j<s.size() && !q.empty()){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(s[j]=='R' && c+1<n){
                    q.push({r,c+1});
                    cnt++;
                }
                if(s[j]=='L' && c-1>=0){
                    q.push({r,c-1});
                    cnt++;
                }
                if(s[j]=='U' && r-1>=0){
                    q.push({r-1,c});
                    cnt++;
                }
                if(s[j]=='D' && r+1<n){
                    q.push({r+1,c});
                    cnt++;
                }
                j++;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};