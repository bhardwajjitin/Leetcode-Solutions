class Solution {
 bool ispossible(int dist, vector<int>& stones) {
    int n = stones.size();
    vector<bool> used(n, false);
    int i = 0, j = 0;
    while (j < n) {
      while (j < n && stones[j] - stones[i] <= dist) {
        j++;
      }
      if (i == j) return false;     
      used[j - 1] = true;       
      i = j - 1;
    }

    int lastindex = n - 1;
    i = n - 1;
    j = n - 1;
    while (j >= 0) {
      while (j >= 0 && stones[i] - stones[j] <= dist) {
        if (!used[j]) {         
          lastindex = j;
          break;    
        }
        j--;
      }
      if (i == lastindex) return false;
      if (stones[i] - stones[lastindex] > dist) return false; 
      i = lastindex;
      if (i == 0) break;
      j = i - 1;
    }
    return lastindex == 0;
  }
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int low = INT_MIN, high;
        for (int i = 1; i < n; i++) {
            low = max(low, stones[i] - stones[i-1]);
        }
        high = stones[n-1] - stones[0];
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ispossible(mid, stones)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
