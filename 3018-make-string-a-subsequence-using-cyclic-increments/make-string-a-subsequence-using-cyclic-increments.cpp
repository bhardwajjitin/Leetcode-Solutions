class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;
        int i = 0;
        while (i < str2.size() && j < str1.size()) {
            char first = str2[i];
            while (j < str1.size() &&
                   (((((str1[j] - 'a' + 1) % 26) + 'a') != first) &&
                    (str1[j] != first))) {
                j++;
            }
            if (j < str1.size() &&
                (((((str1[j] - 'a' + 1) % 26) + 'a') == first) ||
                 (str1[j] == first))) {
                j++;
                i++;
            } else if (j >= str1.size()) {
                break;
            }
        }
        if (i < str2.size())
            return false;
        return true;
    }
};