class Solution {
    private:
    int getminind(unordered_map<int,int>& umap) {
        int minindex = INT_MAX;
        for (auto& it : umap) {
            minindex = std::min(minindex, it.second);
        }
        return minindex;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int cnt = 0;
        int low = 0;
        int i=0;
        int j=0;
        while(j < nums.size()) {
            umap[nums[j]] = j;

            if (umap.size() == k) {
                int minIndex = getminind(umap);
                cnt += (minIndex - low + 1);
            } 
            else if (umap.size() > k) {
                int minIndex = getminind(umap);
                low = minIndex + 1;
                int targetVal = -1;
                for (auto& it : umap) {
                    if (it.second == minIndex) {
                        targetVal = it.first;
                        break;
                    }
                }
                umap.erase(targetVal);
                i=getminind(umap);
                cnt+=i-low+1;
            }
            j++;
        }
        return cnt;
    }
};