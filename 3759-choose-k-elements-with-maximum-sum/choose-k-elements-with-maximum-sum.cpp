class Solution {
private:
    vector<long long> helper(
        vector<pair<pair<int,int>,int>>& arr, int k) {

        int n = arr.size();

        vector<long long> prefix(n, 0);

        priority_queue<int, vector<int>, greater<int>> pq;
        long long currSum = 0;

        int i = 0;

        while (i < n) {

            int j = i;
            while (j < n &&
                   arr[j].first.first == arr[i].first.first) {

                prefix[j] = currSum;
                j++;
            }
            for (int idx = i; idx < j; idx++) {

                int val = arr[idx].first.second;

                pq.push(val);
                currSum += val;

                if (pq.size() > k) {
                    currSum -= pq.top();
                    pq.pop();
                }
            }

            i = j;
        }

        return prefix;
    }

public:
    vector<long long> findMaxSum(vector<int>& nums1,vector<int>& nums2,int k) {

        int n = nums1.size();

        vector<pair<pair<int,int>,int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({{nums1[i], nums2[i]}, i});
        }

        sort(arr.begin(), arr.end());

        vector<long long> res = helper(arr, k);

        vector<long long> ans(n);

        for (int i = 0; i < n; i++) {
            int originalIndex = arr[i].second;
            ans[originalIndex] = res[i];
        }

        return ans;
    }
};