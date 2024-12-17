class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < ranges.size(); i++) {
            int start = max(0, i - ranges[i]);
            int end = min(i + ranges[i], n);
            arr.push_back({start, end});
        }
        sort(arr.begin(), arr.end());
        int lastCovered = 0;
        int nextCovered = 0;
        int i = 0, cnt = 0;

        while (lastCovered < n) {
            while (i < arr.size() && arr[i].first <= lastCovered) {
                nextCovered = max(nextCovered, arr[i].second);
                i++;
            }

            if (nextCovered <= lastCovered) {
                return -1;
            }
            lastCovered = nextCovered;
            cnt++;
        }
        return cnt;
    }
};