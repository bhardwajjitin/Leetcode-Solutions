class Solution {
private:
    void getinsert(vector<int>& nums, vector<int>& arr, int ind) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[arr[mid]] >= nums[ind]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        arr.insert(arr.begin() + low, ind);
    }

    int check(vector<int>& arr, int ele, vector<int>& nums) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[arr[mid]] >= ele) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return high;
    }

public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        stack<int> st1;
        vector<int> ans(nums.size(), -1), arr;

        for (int i = 0; i < nums.size(); i++) {
            int ele = nums[i];

            int index = check(arr, ele, nums);

            for (int j = 0; j <= index; j++) {
                ans[arr[j]] = ele;
            }

            if (index >= 0) {
                arr.erase(arr.begin(), arr.begin() + index + 1);
            }

            while (!st1.empty()) {
                if (nums[i] > nums[st1.top()]) {
                    getinsert(nums, arr, st1.top());
                    st1.pop();
                } else {
                    break;
                }
            }
            st1.push(i);
        }

        return ans;
    }
};