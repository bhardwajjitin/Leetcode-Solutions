class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        vector<int>xcor;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            xcor.push_back(x);
        }
        sort(xcor.begin(),xcor.end());
        int cnt=1;
        int i=0;
        int j=0;
        while(j<xcor.size()){
            if(xcor[j]-xcor[i]<=w){
                j++;
            }
            else{
                i=j;
                cnt++;
            }
        }
        return cnt;
    }
};