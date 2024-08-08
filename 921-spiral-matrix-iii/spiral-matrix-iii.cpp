class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>answer;
        int startrow=rStart;
        int startcol=cStart;
        int endrow=rStart+1;
        int endcol=cStart+1;
        int count=0;
        map<pair<int,int>,int>mp;
        while(count<rows*cols){
            for(int i=startcol;i<=endcol;i++){
                if(i>=0 && i<cols && startrow>=0 && startrow<rows && mp.find({startrow,i})==mp.end()){
                    answer.push_back({startrow,i});
                    count++;
                    mp[{startrow,i}]++;
                }
            }
            startcol--;
            for(int i=startrow;i<=endrow;i++){
                if(i>=0 && i<rows && endcol>=0 && endcol<cols && mp.find({i,endcol})==mp.end()){
                    answer.push_back({i,endcol});
                    count++;
                    mp[{i,endcol}];
                }
            }
            startrow--;
            for(int i=endcol;i>=startcol;i--){
                if(i>=0 && i<cols && endrow>=0 && endrow<rows && mp.find({endrow,i})==mp.end()){
                    answer.push_back({endrow,i});
                    count++;
                    mp[{endrow,i}];
                }
            }
            endcol++;
            for(int i=endrow;i>=startrow;i--){
                if(i>=0 && i<rows && startcol>=0 && startcol<cols && mp.find({i,startcol})==mp.end()){
                    answer.push_back({i,startcol});
                    count++;
                    mp[{i,startcol}];
                }
            }
            endrow++; 
        }
        return answer;
    }
};