class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // first we will make intervals overlapping 
        sort(meetings.begin(),meetings.end());
        int cntdays=meetings[0][0]-1;
        int end=meetings[0][1];
        for(int i=1;i<meetings.size();i++){
            if(end<meetings[i][0]){
                cntdays+=meetings[i][0]-end-1;  
            }
            end=max(end,meetings[i][1]);
        }
        if(end<days){
        cntdays+=days-end;
        }
        return cntdays;
    }
};