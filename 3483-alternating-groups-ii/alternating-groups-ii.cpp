class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int cnt = 0;
        int i = 0;
        int n = colors.size();
        bool res = false;
        while (i < n) {
            bool flag = true;
            if (res == false) {
                for (int j = 1; j < k; j++) {
                    if (colors[(i + j) % n] == colors[(i + (j - 1)) % n]) {
                        i = i + j;
                        flag = false;
                        break;
                    }
                }
            } else {
                int temp =i+k;
                if (colors[(temp - 1)%n] == colors[(temp - 2)%n]) {
                    flag = false;
                    res = false;
                    i++;
                }
            }
            if (flag == true) {
                res = true;
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};
