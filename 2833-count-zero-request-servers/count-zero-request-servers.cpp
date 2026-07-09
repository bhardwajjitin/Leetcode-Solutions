class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<pair<int, int>> q;
        for (int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());

        unordered_map<int, int> umap;
        int activeServers = 0;

        vector<int> res(queries.size());

        int min_time = q[0].first - x;
        int max_time = q[0].first;

        int low = 0, high = logs.size() - 1;

        int first_index = logs.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (logs[mid][1] >= min_time) {
                first_index = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        low = 0;
        high = logs.size() - 1;

        int last_index = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (logs[mid][1] <= max_time) {
                last_index = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        int left = first_index;
        int right = last_index;

        for (int i = left; i <= right; i++) {
            if (umap[logs[i][0]] == 0)
                activeServers++;
            umap[logs[i][0]]++;
        }

        res[q[0].second] = n - activeServers;

        for (int i = 1; i < q.size(); i++) {

            min_time = q[i].first - x;
            max_time = q[i].first;

            low = 0;
            high = logs.size() - 1;

            first_index = logs.size();
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (logs[mid][1] >= min_time) {
                    first_index = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            low = 0;
            high = logs.size() - 1;

            last_index = -1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (logs[mid][1] <= max_time) {
                    last_index = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            while (left < first_index) {
                umap[logs[left][0]]--;
                if (umap[logs[left][0]] == 0)
                    activeServers--;
                left++;
            }

            while (right < last_index) {
                right++;
                if (umap[logs[right][0]] == 0)
                    activeServers++;
                umap[logs[right][0]]++;
            }

            res[q[i].second] = n - activeServers;
        }
        return res;
    }
};