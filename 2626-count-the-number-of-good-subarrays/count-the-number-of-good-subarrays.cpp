class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
       unordered_map<int,int>umap;
       int i=0;
       int j=0;
       long long answer=0;
       long long totalcnt=0;
       while(j<nums.size()){
        umap[nums[j]]++;
        totalcnt+=umap[nums[j]]-1;
        while(i<=j && totalcnt>=k){
            answer+=nums.size()-j;
            totalcnt-=umap[nums[i]]-1;
            umap[nums[i]]--;
            if(umap[nums[i]]==0){
                umap.erase(nums[i]);
            }
            i++;
        }
        j++;
       }
       return answer;
    }
};