class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,long long>umap;
        for(int i=0;i<nums.size();i++){
            int diff=i-nums[i];
            umap[diff]++;
        }
        long long cntgood=0;
        long long totalpair=((nums.size())*(nums.size()-1))/2;
        for(auto it:umap){
            int key=it.first;
            long long value=it.second;
            if(value>=2){
                cntgood+=((value)*(value-1))/2;
            }
        }
        return totalpair-cntgood;
    }
};