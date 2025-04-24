class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int totaldistinct=st.size();
        unordered_map<int,int>umap;
        int i=0,j=0,answer=0;
        while(j<nums.size()){
            umap[nums[j]]++;
            while(i<=j && umap.size()==totaldistinct){
                answer+=nums.size()-j;
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