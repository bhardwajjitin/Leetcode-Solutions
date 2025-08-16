class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int startval=intervals[0][0];
        int endval=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(endval<intervals[i][0]){
                ans.push_back({startval,endval});
                startval=intervals[i][0];
            }
            endval=max(endval,intervals[i][1]);
        }
        ans.push_back({startval,endval});
        return ans;
    }
};