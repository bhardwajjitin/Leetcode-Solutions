class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>arr;
        for(int i=0;i<ranges.size();i++){
            int start=max(i-ranges[i],0);
            int end=min(i+ranges[i],n);
            if(start==end)continue;
            arr.push_back({start,end});
        }
        sort(arr.begin(),arr.end());
        int cnt=0;
        int start=0;
        int last=0;
        int i=0;
        while(start<n) {
            while (i<arr.size() && arr[i].first<=start) {
                last=max(last,arr[i].second);
                i++;
            }
            if (last==start) return -1;
            start=last;
            cnt++;
        }

        return cnt;
    }
};