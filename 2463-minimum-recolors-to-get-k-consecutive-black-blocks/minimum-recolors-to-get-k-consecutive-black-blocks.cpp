class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        vector<int> pre(blocks.size(), 0);
        int prev = 0;
        int mini = INT_MAX;
        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i] == 'W') {
                pre[i] = prev + 1;
                prev = pre[i];
            } else {
                pre[i] = prev;
            }
        }
        for (int i = k-1; i < pre.size(); i++) {
            int right = pre[i];
            int left = (i - k>= 0) ? pre[i - k] : 0;
            int cnt = right - left;
            mini = min(cnt, mini);
        }
        return mini;
    }
};