class Solution {
private:
    int getsetbits(int num) {
        int count = 0;
        while (num != 0) {
            if (num & 1 != 0) {
                count++;
            }
            num >>= 1;
        }
        return count;
    }

public:
    int minimizeXor(int num1, int num2) {
        int countsetbit = getsetbits(num2);
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if (num1 & (1 << i) && countsetbit != 0) {
                ans |= (1 << i);
                countsetbit--;
            }
        }
        for (int i = 0; i <= 31 && countsetbit > 0; i++) {
            if ((num1 & (1 << i)) == 0) {
                ans |= (1 << i);
                countsetbit--;
            }
        }
        return ans;
    }
};