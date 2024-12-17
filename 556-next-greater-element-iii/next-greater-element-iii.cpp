class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> arr;
        while (n != 0) {
            int r = n % 10;
            arr.push_back(r);
            n /= 10;
        }
        reverse(arr.begin(), arr.end());
        bool flag = false;
        for (int i = arr.size() - 2; i >= 0; i--) {
            int curr = arr[i];
            int swapind = -1;
            int mini = INT_MAX;
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] < arr[j] && mini > arr[j]) {
                    swapind = j;
                    mini = arr[j];
                }
            }
            if (swapind != -1) {
                flag = true;
                swap(arr[i], arr[swapind]);
                sort(arr.begin() + i + 1, arr.end());
                break;
            }
        }
        int number = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (number > (INT_MAX - arr[i]) / 10) {
                return -1;
            }
            number = number * 10 + arr[i];
        }
        return flag == false ? -1 :number;
    }
};