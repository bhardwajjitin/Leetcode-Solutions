class comp{
    public:
    bool operator()(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inte) {
        sort(inte.begin(),inte.end(),comp());
        int cnt=0;
        int end=inte[0][1];
        for(int i=1;i<inte.size();i++){
            int first=inte[i][0];
            if(end>first)cnt++;
            else if(end<=first){
                end=inte[i][1];
            }
        }
        return cnt;
    }
};