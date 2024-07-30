class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int cnt=0;
        for(int size=1;size<=nums.size();size++){
            int i=0;
            int j=0;
            unordered_map<int,int>umap;
            while(j<nums.size()){
                umap[nums[j]]++;
                if(j-i+1<size)j++;
                else if(j-i+1==size){
                    cnt+=pow(umap.size(),2);
                    umap[nums[i]]--;
                    if(umap[nums[i]]==0)umap.erase(nums[i]);
                    i++;
                    j++;
                }
            }
        }
        return cnt;
    }
};